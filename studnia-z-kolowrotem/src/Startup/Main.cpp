#include "LibraryExceptions/ShaderException.h"
#include "MainWindow.h"
#include "Scene.h"

#include <iostream>
#include <locale>
#include <typeinfo>

namespace {
	void setupLocale() {
		std::locale loc;

		try {
			loc = std::locale{"pl"};
		} catch(const std::exception& e) {
			loc = std::locale{""};
			std::cerr << "Application failed to use `pl` locale (" << e.what() << ").\n";
		}

		std::cerr << "Current locale: `" << loc.name() << "` locale.\n";
		std::locale::global(loc);
		std::cout.imbue(loc);
	}

	void handleUnexpectedException(const std::exception& e) {
		std::cerr << "Unexpected exception:\n"
			"  what(): \"" << e.what() << "\"\n";

		if(auto* syserr = dynamic_cast<const std::system_error*>(&e)) {
			std::cerr << "  code(): " << syserr->code() << '\n';
		}

		std::cerr << "  exception type name: \"" << typeid(e).name() << "\"\n";
	}

	void handleShaderException(const ShaderException& e) {
		std::cerr << "Unexpected shader exception:\n"
			"  what(): \"" << e.what() << "\"\n"
			"  id: " << e.getAssociatedId() << "\n"
			"  situation: " << e.getSituation() << '\n';
	}

	void glfwErrorCallback(int errorCode, const char* description) {
		std::cerr << "[glfw:" << errorCode << "] " << description << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cerr.tie(nullptr);
	setupLocale();

	if(!glfwInit()) {
		std::cerr << "glfw initialization failed\n";
		return EXIT_FAILURE;
	}

	glfwSetErrorCallback(&glfwErrorCallback);

	try {
		MainWindow window;
		window.makeContextCurrent();

		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK) {
			std::cerr << "glew initialization failed\n";
			return EXIT_FAILURE;
		}

		Scene scene{window};
		scene.start();

	} catch(const ShaderException& e) {
		handleShaderException(e);
	} catch(const std::exception& e) {
		handleUnexpectedException(e);
	} catch(...) {
		std::cerr << "Unexpected exception...\n";
	}

	glfwTerminate();
}

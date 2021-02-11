#include "Graphics/Shader/ShaderException.h"
#include "MainWindow.h"
#include "Scene.h"

#include <iostream>
#include <locale>
#include <typeinfo>

namespace {
	void setupLocale() {
		try {
			std::locale loc{""};
			std::locale::global(loc);
			std::cout.imbue(loc);
		} catch(const std::runtime_error& e) {
			std::cerr << "Program failed to use custom locale: `" << e.what() << "`\n";
		}
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
			"  shader id: " << e.getAssociatedId() << "\n"
			"  situation: " << e.getSituation() << "\n"
			"  what():\n    ";

		for(char symbol : std::string_view{e.what()}) {
			std::cerr << symbol;
			if(symbol == '\n') {
				std::cerr << "    ";
			}
		}
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

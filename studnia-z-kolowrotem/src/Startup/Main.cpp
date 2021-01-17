#include "Scene.h"
#include <filesystem>
#include <iostream>
#include "MainWindow.h"
#include <typeinfo>

namespace filesystem = std::filesystem;

namespace {
	void handleUnexpectedException(const std::exception& e) {
		std::cerr << "Unexpected exception:\n"
			"  what(): \"" << e.what() << "\"\n";

		if(auto* syserr = dynamic_cast<const std::system_error*>(&e)) {
			std::cerr << "  code(): " << syserr->code() << '\n';
		}

		std::cerr << "  exception type name: \"" << typeid(e).name() << "\"\n";
	}

	void glfwErrorCallback(int errorCode, const char* description) {
		std::cerr << "[glfw:" << errorCode << "] " << description << '\n';
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cerr.tie(nullptr);

	if(!glfwInit()) {
		std::cerr << "glfw initialization failed\n";
		return EXIT_FAILURE;
	}

	glfwSetErrorCallback(&glfwErrorCallback);

	try {
		MainWindow window;

		glewExperimental = GL_TRUE;
		if(glewInit() != GLEW_OK) {
			std::cerr << "glew initialization failed\n";
			return EXIT_FAILURE;
		}

		std::cerr << "program info:\n"
			"  current path: " << filesystem::current_path() << '\n';

		Scene scene{window};
		scene.start();

	} catch(const std::exception& e) {
		handleUnexpectedException(e);
		return EXIT_FAILURE;
	} catch(...) {
		std::cerr << "Unexpected exception...\n";
		return EXIT_FAILURE;
	}

	glfwTerminate();
}

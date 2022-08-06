#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstdio>

#include "glad/glad.h"
#include "GLFW/glfw3.h"


#include "TT55/Shader/Shader.h"
#include "TT55/window.h"
#include "TT55/listeners.h"
#include "TT55/renderer.h"
// #define CALLBACK_DEBUG
#include "TT55/callbacks.h"





int main() 
{
	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		exit(1);
	}
	std::cout << "GLFW v" <<  glfwGetVersionString() << std::endl;



	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef DEVICE_APPLE
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


	// set `window_s Window` parameters
	TT55::Window.wireframe 	= false;
	TT55::Window.width 		= 800;
	TT55::Window.height 	= 600;
	TT55::Window.name 		= "Test";
	// Create `GLFWwindow window`
	GLFWwindow* window = TT55::createWindow(TT55::Window);
	glfwMakeContextCurrent(window); // make glfw / opengl context

	TT55::Window.window = window;

	// load / initialize glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		glfwTerminate(); // terminate glfw incase glad could not be loaded / initialized
		return -1;
	}

	// Set Viewport to size of window
	glViewport(0, 0, TT55::Window.width, TT55::Window.height);

	Shader shader("src/shaders/default.vert", "src/shaders/default.frag");
	TT55::Window.shader = shader;
	
	// callbacks
	glfwSetFramebufferSizeCallback(window, 	TT55::Callbacks::window_resize_callback); // set resize callback
	glfwSetErrorCallback(					TT55::Callbacks::glfw_error_callback);
	glfwSetKeyCallback(window, 				TT55::Callbacks::window_key_callback);
	glfwSetCharCallback(window, 			TT55::Callbacks::window_char_callback);
	glfwSetMouseButtonCallback(window, 		TT55::Callbacks::window_mouse_button_callback);
	glfwSetCursorPosCallback(window, 		TT55::Callbacks::window_cursor_position__callback);
	glfwSetCursorEnterCallback(window, 		TT55::Callbacks::window_cursor_enterWindow);
	glfwSetScrollCallback(window,			TT55::Callbacks::window_scroll_callback);



	TT55::Renderer::renderLoop(TT55::Window);

	


	// terminate glfw
	glfwTerminate();
	return 0; // return
}

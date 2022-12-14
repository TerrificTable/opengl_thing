namespace TT55 {

    // Window_s struct, contains some information about the window
    struct window_s {
        GLFWwindow* window;
        
        int width;
        int height;
        const char* name;
        Shader shader;


        bool wireframe;
    } Window;


    // Create GLFWwindow
    GLFWwindow *createWindow(window_s WINDOW) {

        // Create the window
        GLFWwindow* window = glfwCreateWindow(WINDOW.width, WINDOW.height, WINDOW.name, NULL, NULL);

        // check if window was created successfully
        if (!window) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate(); // terminate glfw incase window was not created successfully
            exit(1); // exit
        }

        return window; // return `window` object
    }


}

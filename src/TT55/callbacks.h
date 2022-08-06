namespace TT55::Callbacks { 


    void window_resize_callback(GLFWwindow* window, int width, int height) {
        TT55::Window.width = width; // set Window.width
        TT55::Window.height = height; // set Window.height
        glViewport(0, 0, TT55::Window.width, TT55::Window.height); // change viewport size

#ifdef CALLBACK_DEBUG
        std::cout << "[CALLBACK] <Resize> W: " << TT55::Window.width << "\tH: " << TT55::Window.height << std::endl;
#endif
    }


    void glfw_error_callback(int error_code, const char* description) {
        std::cout << "GLFW Error \t[" << error_code << "]\t" << description << std::endl;
    }

    void window_key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
        std::string action_word;
        switch (action) {
            case 0:
                action_word = "Release";
                break;
            case 1:
                action_word = "Press";
                break;
            case 2:
                action_word = "Hold";
                break;
            default:
                action_word = "?";
                break;
        }

#ifdef CALLBACK_DEBUG
        std::cout << "[CALLBACK] <Key>" 
            << " Mod,Key: [" << mods << "][" << std::hex << key << "]  " 
            << "Action: [" << action << " | " << action_word << "]  "
            << "ScanCode: [" << scancode << "]" 
            << std::endl;
#endif
    }

    void window_char_callback(GLFWwindow* window, unsigned int codepoint) {
#ifdef CALLBACK_DEBUG
        std::cout << "[CALLBACK] <Char> codePoint: " << codepoint << std::endl;
#endif
    }

    void window_mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
        std::string button_string;
        switch (button) {
            case GLFW_MOUSE_BUTTON_RIGHT:
                button_string = "Right";
                break;
            case GLFW_MOUSE_BUTTON_LEFT:
                button_string = "Left";
                break;
            case GLFW_MOUSE_BUTTON_MIDDLE:
                button_string = "Middle";
                break;
            default:
                button_string = "?";
                break;
        }
        std::string action_string;
        switch (action) {
            case 0:
                action_string = "Release";
                break;
            case 1:
                action_string = "Press";
                break;
            case 2:
                action_string = "Hold";
                break;
            default:
                action_string = "?";
                break;
        }

#ifdef CALLBACK_DEBUG
        std::cout << "[CALLBACK] <Mouse Button>" 
            << "Button: [" << button << " | " << button_string << "]  "
            << "Action: [" << action << " | " << action_string << "]  " 
            << "Mod: [" << mods << "]" 
            << std::endl;
#endif
    }

    void window_cursor_position__callback(GLFWwindow* window, double xpos, double ypos) {
#ifdef CALLBACK_DEBUG
            // std::cout << "[CALLBACK] <Cursor Pos> " 
            //     << "X: [" << xpos << "]  "
            //     << "Y: [" << ypos << "]  "
            //     << std::endl;
#endif
    }

    void window_cursor_enterWindow(GLFWwindow* window, int entered) {
#ifdef CALLBACK_DEBUG
        std::cout << "[CALLBACK] <Curosr Enter Window> "
            << "Entered: [" << entered << "]"
            << std::endl;
#endif
    } 

    void window_scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
#ifdef CALLBACK_DEBUG
        std::cout << "[CALLBACK] <Scroll> "
            << "XOffset: [" << xoffset << "]  "
            << "YOffset: [" << yoffset << "]"
            << std::endl;
#endif
    }


} 

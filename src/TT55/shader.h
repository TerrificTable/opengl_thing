namespace TT55::Shader {

    std::string load_shader(const char*);


    int compile_link() {
        int success;
        char infoLog[512];
        
        /*
        const char *vertex_shader_src = "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "void main() {\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
            "}\0";
        const char *fragment_shader_src = "#version 330 core\n"
            "out vec4 FragColor;\n"
            "void main() {\n"
            "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\0";
        */

        std::string vertex_shader_src_str = load_shader("src/shaders/default.vert");
        std::string fragment_shader_src_str = load_shader("src/shaders/default.frag");
        const char *vertex_shader_src = vertex_shader_src_str.c_str();
        const char *fragment_shader_src = fragment_shader_src_str.c_str();

        // Compile Vertex Shader
        unsigned int vertexID;
        vertexID = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexID, 1, &vertex_shader_src, NULL);
        glCompileShader(vertexID);

        glGetShaderiv(vertexID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexID, 512, NULL, infoLog);
            std::cout << "ERROR Compile Vertex Shader: ID [" << vertexID << "]   error: " << infoLog << std::endl;
            exit(1);
        }



        // Compile Fragment Shader
        unsigned int fragmentID;
        fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentID, 1, &fragment_shader_src, NULL);
        glCompileShader(fragmentID);

        glGetShaderiv(fragmentID, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
            exit(1);
        }        



        // Link shaders
        unsigned int programID;
        programID = glCreateProgram();
        glAttachShader(programID, vertexID);
        glAttachShader(programID, fragmentID);
        glLinkProgram(programID);
        // check for linking errors
        glGetProgramiv(programID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(programID, 512, NULL, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);


        return programID;
    }



    std::string load_shader(const char* filename) {
        std::string shader_src_file_contents; 
        std::fstream file;

        file.open(filename);
        if (file.is_open()) {
            std::string tp;
            while (getline(file, tp)) {
                shader_src_file_contents += tp;
                shader_src_file_contents += "\n";
            }
            file.close();
        }
        shader_src_file_contents += "\0";

#ifdef SHADER_DEBUG
        std::cout << "ShaderFile: " << shader_src_file_contents << std::endl;
#endif

        return shader_src_file_contents;
    }

    
} // namespace TT55::Shader

#define SHADER_DEBUG

#include "Shader.h"


std::string readFile(const char* filename);


Shader::Shader(std::string vertex_src, std::string fragment_src) {

    readShadersFromFile(vertex_src, fragment_src);
    init();

}


void Shader::readShadersFromFile(std::string vertex_shader_src_path, std::string fragment_shader_src_path) {

    vertex_shader_src = readFile(vertex_shader_src_path.c_str()).c_str();
    fragment_shader_src = readFile(fragment_shader_src_path.c_str()).c_str();

}

void Shader::init() {
    
    int success;
    char infoLog[512];

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

}


void Shader::use() {
    glUseProgram(programID);
}

void Shader::setBool(const std::string &name, bool value) {
    glUniform1i(glGetUniformLocation(programID, name.c_str()), (int)value);
}
void Shader::setInt(const std::string &name, int value) {
    glUniform1i(glGetUniformLocation(programID, name.c_str()), value);   
}
void Shader::setFloat(const std::string &name, float value) {
    glUniform1f(glGetUniformLocation(programID, name.c_str()), value);
}



std::string readFile(const char* filename) {
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

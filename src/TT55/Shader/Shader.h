#ifndef SHADER_H
#define SHADER_H

#include "../../../include/glad/glad.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include <string>



class Shader {

private:
    GLuint vertexID;
    GLuint fragmentID;
    const char* vertex_shader_src;
    const char* fragment_shader_src;

    void readShadersFromFile(std::string vertex_shader_src_path, std::string fragment_shader_src_path);
    void init();

public:
    GLuint programID;
    
    Shader(std::string vertex_path, std::string fragment_path);


    void use();

    void setBool(   const std::string &name, bool     value   );
    void setInt(    const std::string &name, int      value   );
    void setFloat(  const std::string &name, float    value   );

};


#endif

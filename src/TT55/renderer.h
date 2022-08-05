#include <math.h>

#include "VBO/VBO.h"
#include "VAO/VAO.h"
#include "EBO/EBO.h"


namespace TT55::Renderer {

    float vertices[] = {
        // POSITION          /       COLOR
         0.5f,  0.5f, 0.0f,     1.0f,  0.0f, 0.25f,   // top right
         0.5f, -0.5f, 0.0f,     0.75f, 0.5f, 0.5f,    // bottom right
        -0.5f, -0.5f, 0.0f,     0.5f,  1.0f, 0.75f,   // bottom left
        -0.5f,  0.5f, 0.0f,     0.25f, 0.0f, 1.0f     // top left 

        // POSITION          /       COLOR
        //  0.0f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f,   // TOP
        //  0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,   // BOTTOM RIGHT
        // -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f    // BOTTOM LEFT
    };

    float vertices_1[] = {
        // POSITION          /       COLOR
         0.0f,  0.5f, 0.0f,     1.0f, 0.0f, 0.0f,   // TOP
         0.5f, -0.5f, 0.0f,     0.0f, 1.0f, 0.0f,   // BOTTOM RIGHT
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f    // BOTTOM LEFT
    };

    GLuint indices[] = {
        0, 1, 3,
        1, 2, 3
    };
    GLuint indices_1[] = {
        0, 1, 2
    };



    void render(GLFWwindow*, int, VAO[]);


    void renderLoop(TT55::Window_s Window) {
    
        GLFWwindow* window = Window.window;

        
        VAO vao;
        vao.Bind();

        VBO vbo(vertices, sizeof(vertices));
        EBO ebo(indices, sizeof(indices));

        vao.LinkVBO(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
        vao.LinkVBO(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        vao.Unbind();
        vbo.Unbind();
        ebo.Unbind();

        VAO vao_1;
        vao_1.Bind();

        VBO vbo_1(vertices_1, sizeof(vertices_1));
        EBO ebo_1(indices_1, sizeof(indices_1));

        vao_1.LinkVBO(vbo, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
        vao_1.LinkVBO(vbo, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        vao_1.Unbind();
        vbo_1.Unbind();
        ebo_1.Unbind();




        while (!glfwWindowShouldClose(window)) {
            // Input
            TT55::Listeners::processInputListener(window);


            VAO vaos[] = {
                vao, vao_1
            };

            // === RENDERING === //
            render(window, TT55::Window.programID, vaos);
            // === RENDERING === //


            // check and call events and swap buffers
            glfwPollEvents(); // poll window eventsx
            glfwSwapBuffers(window); // swap frame buffers
	    }

        vao.Delete();
        vbo.Delete();
        ebo.Delete();
    
        vao_1.Delete();
        vbo_1.Delete();
        ebo_1.Delete();

    }

    void render(GLFWwindow* window, int programID, VAO vaos[]) {

        TT55::Window.wireframe_toggle_time++;


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);



        glUseProgram(programID);
        float u_time = glfwGetTime();
        float u_scale = 0.5f;
        int u_time_location = glGetUniformLocation(programID, "u_time");
        int u_scale_location = glGetUniformLocation(programID, "u_scale");
        glUniform1f(u_time_location, u_time);
        glUniform1f(u_scale_location, u_scale);

        
        // vaos[0].Bind();
        vaos[1].Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);


    }


} // namespace TT55::Renderer

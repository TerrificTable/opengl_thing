#include <math.h>

#include "VBO/VBO.h"
#include "VAO/VAO.h"
#include "EBO/EBO.h"
#include "Shape/shapes/triangle.h"
#include "Shape/shapes/rectangle.h"

namespace TT55::Renderer {


    void render(GLFWwindow*, Shader, VAO[]);


    void renderLoop(TT55::window_s Window) {
    
        GLFWwindow* window = Window.window;

        
        float r_tr[] = {  0.5f,  0.5f, 0.0f,    1.0f,  0.0f, 0.25f };
        float r_br[] = {  0.5f, -0.5f, 0.0f,    0.75f, 0.5f, 0.5f  };
        float r_bl[] = { -0.5f, -0.5f, 0.0f,    0.5f,  1.0f, 0.65f };
        float r_tl[] = { -0.5f,  0.5f, 0.0f,    0.25f, 0.0f, 1.0f  };
        Rectangle rectangle(r_tl, r_tr, r_bl, r_br);

        float t_bl[] = { -0.25f - 0.5f, -0.25f, 0.0f,     1.0f, 0.0f, 0.0f };
        float t_br[] = {  0.25f - 0.5f, -0.25f, 0.0f,     0.0f, 1.0f, 0.0f };
        float t_t[]  = {  0.0f  - 0.5f,  0.25f, 0.0f,     0.0f, 0.0f, 1.0f };
        Triangle triangle(t_bl, t_br, t_t);


        VAO vaos[] = {};

        while (!glfwWindowShouldClose(window)) {
            // Input
            TT55::Listeners::processInputListener(window);


            // === RENDERING === //
            render(window, TT55::Window.shader, vaos);

            rectangle.Draw();
            triangle.Draw();
            // === RENDERING === //


            // check and call events and swap buffers
            glfwPollEvents(); // poll window events
            glfwSwapBuffers(window); // swap frame buffers
	    }

        rectangle.Delete();
        triangle.Delete();

    }

    void render(GLFWwindow* window, Shader shader, VAO vaos[]) {


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);



        glUseProgram(shader.programID);
        float u_time = glfwGetTime();
        float u_scale = 0.5f;
        int u_time_location = glGetUniformLocation(shader.programID, "u_time");
        int u_scale_location = glGetUniformLocation(shader.programID, "u_scale");
        glUniform1f(u_time_location, u_time);
        glUniform1f(u_scale_location, u_scale);

        
        // vaos[0].Draw(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        // vaos[1].Draw(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);

    }


} // namespace TT55::Renderer

#include "../../VAO/VAO.h"
#include "../../VBO/VBO.h"
#include "../../EBO/EBO.h"

#include "../../Shader/Shader.h"


class Triangle {

public:
    VAO vao;
    VBO vbo;
    EBO ebo;

    // *inp* => -1.0 : 1.0
    Triangle(float bottom_left[], float bottom_right[], float top[]);

    void Delete();
    void Draw(Shader shader);
    void Draw();

};


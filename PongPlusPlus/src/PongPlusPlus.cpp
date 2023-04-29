#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        std::cout << "Couldn't initialize glew!" << std::endl;
        return -1;
    }

    // TODO: 1- Vertex buffer
    //       2- Index buffer
    //       3- VAO
    //       4- buffer layout

    float verticies[] = {
        -0.5f, -0.5f,  // 0
         0.5f, -0.5f,  // 1
         0.0f,  1.0f   // 2
    };

    uint32_t indicies[] = {
        0, 1, 2
    };

    uint32_t vb;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ARRAY_BUFFER, vb);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 6, verticies, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
    glEnableVertexAttribArray(0);

    uint32_t ib;
    glGenBuffers(1, &vb);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vb);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * 3, indicies, GL_STATIC_DRAW);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, &ib);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
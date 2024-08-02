#include "renderer.hpp"

namespace Tetris {

Renderer::Renderer() {
    fmt::print("Renderer Constructor\n");

    // m_shaderProgram = m_shaderManager.compileAndLinkShaders();
    // glUseProgram(m_shaderProgram);
}
 
Renderer::~Renderer() {
    fmt::print("Renderer Destructor\n");
}

void Renderer::render(const GameState& state) {
    // fmt::print("Rendering\n");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // draw blocks
    // for (auto& obj : blocks) {
    //     m_shaderManager.transform(obj.getGameObject()->getModelMatrix(), obj.getGameObject()->getColor());
    //     glBindVertexArray(m_blockVAO);
    //     glDrawArrays(GL_TRIANGLES, 0, 3);
    // }

    glfwSwapBuffers(m_window);
    glfwPollEvents();
}

void Renderer::setWindow(GLFWwindow* window) {
    m_window = window;
}




// void Renderer::setShaderProgram(GLuint shaderProgram) {
//     m_shaderProgram = shaderProgram;
// }

// GLuint Renderer::getShaderProgram() {
//     return m_shaderProgram;
// }

// void Renderer::printCurrentMatrix(GameObject* obj) {
//     auto modelMatrix = obj->getModelMatrix();
//     fmt::print("Model matrix:\n");
//     for (int i = 0; i < 4; ++i) {
//         fmt::print("{}, {}, {}, {}\n", modelMatrix[i][0], modelMatrix[i][1], modelMatrix[i][2], modelMatrix[i][3]);
//     }
// }

// std::array<GLfloat, 21> Renderer::getCombinedData(GameObject* obj) {
//     auto vertices = obj->calculateTriangleVertices();
//     std::array<GLfloat, 21> combinedData;

//     for (int i = 0; i < 3; ++i) {
//         combinedData[i * 7 + 0] = vertices[i].x;   // x
//         combinedData[i * 7 + 1] = vertices[i].y;   // y
//         combinedData[i * 7 + 2] = vertices[i].z;   // z
//         combinedData[i * 7 + 3] = obj->m_color.r;  // r
//         combinedData[i * 7 + 4] = obj->m_color.g;  // g
//         combinedData[i * 7 + 5] = obj->m_color.b;  // b
//         combinedData[i * 7 + 6] = obj->m_color.a;  // a
//     }

//     return combinedData;
// }

// void Renderer::initializeVertexData(std::vector<std::vector<float>> vertices) {
//     // block vao and vbo
//     glGenVertexArrays(1, &m_playerVAO);
//     glGenBuffers(1, &m_playerVBO);
//     glBindVertexArray(m_playerVAO);
//     glBindBuffer(GL_ARRAY_BUFFER, m_playerVBO);
//     glBufferData(GL_ARRAY_BUFFER, vertices[0].size() * sizeof(float), vertices[0].data(), GL_STATIC_DRAW);
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)0);
//     glEnableVertexAttribArray(0);
//     glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
//     glEnableVertexAttribArray(1);

//     glBindBuffer(GL_ARRAY_BUFFER, 0);
//     glBindVertexArray(0);
// }

}  // namespace Tetris
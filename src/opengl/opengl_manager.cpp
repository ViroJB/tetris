#include "opengl_manager.hpp"

OpenGLManager::OpenGLManager() {

}

OpenGLManager::~OpenGLManager() {

}

void OpenGLManager::initialize() {
    if(!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }
}

void OpenGLManager::createWindow(const char* title, int width, int height) {
    m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!m_window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    
    glfwSetFramebufferSizeCallback(m_window, framebufferSizeCallback);
    glfwMakeContextCurrent(m_window);

    glfwSwapInterval(1);                                // disable v-sync (0 false, 1 true)
    glEnable(GL_BLEND);                                 // enable blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  // enable transparency


    // NOTE we need the m_window already opened before calling this
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
        // return nullptr;
    }
}

GLFWwindow* OpenGLManager::getWindow() {
    return m_window;
}

void OpenGLManager::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}
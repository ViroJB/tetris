#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <fmt/core.h>
#include <iostream>

class OpenGLManager {
   public:
    OpenGLManager();
    ~OpenGLManager();

    void initialize();

    void createWindow(const char* title, int width, int height);
    GLFWwindow* getWindow();

   private:
    GLFWwindow* m_window = nullptr;
    static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
};
//
// Created by deril on 9/10/24.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "UGLWindow.h"
#include <functional>

namespace Ursa::GL {
    UGLWindow::UGLWindow(const Properties &properties): UWindow(properties) {
        m_Window = glfwCreateWindow(m_Properties.width, m_Properties.height, m_Properties.title.c_str(), NULL, NULL);

        if (!m_Window) {
            throw std::runtime_error("Failed to create GLFW window");
        }
        glfwMakeContextCurrent(m_Window);


        glewExperimental = GL_TRUE;
        GLFWwindow* window = glfwGetCurrentContext();
        if(glewInit() != GLEW_OK) {
            throw std::runtime_error("Failed to initialize GLEW");
        }

        glfwSetWindowUserPointer(m_Window, this);

        glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            glViewport(0, 0, width, height);
            auto* wrapper = static_cast<UGLWindow *>(glfwGetWindowUserPointer(window));
            wrapper->setSize(width, height);
        });
    }

    bool UGLWindow::ShouldClose() const {
        return glfwWindowShouldClose(m_Window);
    }

    void UGLWindow::SwapBuffers() {
        glfwSwapBuffers(m_Window);
    }

    UGLWindow::~UGLWindow() {
        glfwDestroyWindow(m_Window);
    }
}

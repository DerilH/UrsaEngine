//
// Created by deril on 9/10/24.
//
#include "UGLRenderer.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Ursa::GL {
    UGLRenderer::UGLRenderer(const Ref<Render::UWindow> window, const std::map<std::string, Ref<Render::Shaders::UShaderProgram>> &shaderLibrary) : URenderer(window, shaderLibrary) {
    }

    void UGLRenderer::Clear() {
        glClearColor(0.1f,0.1f,0,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void UGLRenderer::Present() {
        m_Window->SwapBuffers();
        glfwPollEvents();
    }

    void UGLRenderer::RenderTriangle() {
        m_ShaderLibrary.at("Base")->Bind();
        // glBindVertexArray(VAO);
        // glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    UGLRenderer::~UGLRenderer() = default;
}

//
// Created by deril on 9/10/24.
//

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "UOpengGLAPI.h"
#include "UGLRenderer.h"
#include "UGLWindow.h"
#include "../../core/logging/Logging.h"

namespace Ursa::GL {
    void UOpenGLAPI::Init() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifndef NDEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
#endif

        m_initialized = true;
    }

    void UOpenGLAPI::Terminate() {
        glfwTerminate();
    }

    Ref<Render::UWindow> UOpenGLAPI::CreateWindow(const Render::UWindow::Properties properties) {
        assert(m_initialized);
        return CreateDerivedRef<Render::UWindow>(new UGLWindow(properties));
    }

    Ref<Render::URenderer> UOpenGLAPI::CreateRenderer(const Ref<Render::UWindow> &window, std::map<std::string, Ref<Render::Shaders::UShaderProgram>> &shaderLibrary) {
        assert(m_initialized);
        return CreateDerivedRef<Render::URenderer>(new UGLRenderer(window, shaderLibrary));
    }

    void UOpenGLAPI::EnableDebug() {
        glEnable(GL_DEBUG_OUTPUT);

        if (GLEW_KHR_debug)
        {
            LOG_ERROR("KHR_debug extension found\n");
            glDebugMessageCallback([](auto source, auto type, auto id, auto severity, auto length, auto message, auto userParam) {
                LOG_INFO(message);
            }, nullptr);
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
            LOG_INFO("debug callback enabled\n");
        }
        else if(GL_ARB_debug_output)
        {
            LOG_ERROR("GL_ARB_debug_output extension found\n");
            glDebugMessageCallback([](auto source, auto type, auto id, auto severity, auto length, auto message, auto userParam) {
                LOG_INFO(message);
            }, nullptr);
            LOG_INFO("debug callback enabled\n");
            glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
        }
        else
        {
            LOG_INFO("KHR_debug extension NOT found\n");
        }
    }
}


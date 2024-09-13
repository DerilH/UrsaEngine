//
// Created by deril on 9/10/24.
//

#pragma once
#include "../../core/render/UWindow.h"
#include <GLFW/glfw3.h>

namespace Ursa::GL {
    class UGLWindow : Render::UWindow {
        friend class UOpenGLAPI;

        GLFWwindow* m_Window;
        explicit UGLWindow(const Properties &properties);
    public:
        ~UGLWindow() override;
        bool ShouldClose() const override;
        void SwapBuffers() override;
    };


}

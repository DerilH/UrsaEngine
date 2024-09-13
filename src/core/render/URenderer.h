//
// Created by deril on 9/10/24.
//
#pragma once
#include "UWindow.h"

namespace Ursa::Render {
    class URenderer {
    protected:
        Ref<UWindow> m_Window;
        const std::map<std::string, Ref<Shaders::UShaderProgram>>& m_ShaderLibrary;
    public:
        URenderer(Ref<UWindow> window, const std::map<std::string, Ref<Shaders::UShaderProgram>> &shaderLibrary);
        virtual ~URenderer() = default;
        virtual void Clear() = 0;
        virtual void Present() = 0;
        virtual void RenderTriangle() = 0;
    };
}

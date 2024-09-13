//
// Created by deril on 9/10/24.
//
#pragma once
#include "../../core/render/URenderer.h"

namespace Ursa::GL {
    class UGLRenderer final : public Render::URenderer {
    public:
        UGLRenderer(Ref<Render::UWindow> window, const std::map<std::string, Ref<Render::Shaders::UShaderProgram>> &shaderLibrary) ;

        void Clear() override;

        void Present() override;

        void RenderTriangle() override;

        ~UGLRenderer() override;
    };
}

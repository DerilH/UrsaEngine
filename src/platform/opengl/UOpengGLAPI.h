//
// Created by deril on 9/10/24.
//
#pragma once
#include "../../core/render/UGraphicsAPI.h"


namespace Ursa::GL {
    class UOpenGLAPI : public Render::UGraphicsAPI {
    public:
        void Init() override;
        void Terminate() override;

        Ref<Render::UWindow> CreateWindow(Render::UWindow::Properties properties) override;
        Ref<Render::URenderer> CreateRenderer(const Ref<Render::UWindow> &window, std::map<std::string, Ref<Render::Shaders::UShaderProgram>> &shaderLibrary) override;
        void EnableDebug() override;
    };
}

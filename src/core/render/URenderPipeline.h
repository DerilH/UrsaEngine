//
// Created by deril on 9/10/24.
//
#pragma once
#include <thread>

#include "UGraphicsAPI.h"
#include "URenderer.h"
#include "../declarations.h"
#include "../../platform/opengl/UOpengGLAPI.h"


namespace Ursa::Render {
    class URenderer;

    class URenderPipeline {
        std::map<std::string, Ref<Shaders::UShaderProgram>> m_ShaderLibrary;
        Ref<UWindow> m_Window;
        Ref<URenderer> m_Renderer;
    public:
        explicit URenderPipeline();
        ~URenderPipeline();
        void Init();
        void Terminate();
        void Run() const;

        static Ref<UGraphicsAPI> GraphicsAPI() {
            static auto api = CreateDerivedRef<UGraphicsAPI>(new GL::UOpenGLAPI);
            return api;
        }

        UGraphicsAPIType getAPIType();
        void RegisterShader(const std::string& name, const Ref<Shaders::UShaderProgram>& shader);
    };
}

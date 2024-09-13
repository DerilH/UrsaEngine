//
// Created by deril on 9/10/24.
//
#pragma once
#include "URenderer.h"
#include "../declarations.h"

namespace Ursa::Render {
    class UGraphicsAPI {
    protected:
        bool m_initialized = false;

    public:
        virtual ~UGraphicsAPI() = default;

        virtual void Init() = 0;
        virtual void Terminate() = 0;
        bool IsInitialized() const { return m_initialized; }

        virtual Ref<UWindow> CreateWindow(UWindow::Properties properties) = 0;
        virtual Ref<URenderer> CreateRenderer(const Ref<UWindow> &window, std::map<std::string, Ref<Shaders::UShaderProgram>> &shaderLibrary) = 0;
        virtual void EnableDebug() = 0;
    };

    enum class UGraphicsAPIType {
        OPENGL,
        VULKAN,
        DIRECTX
    };
}

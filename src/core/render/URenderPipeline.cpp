//
// Created by deril on 9/10/24.
//

#include "URenderPipeline.h"
#include "URenderer.h"
#include "../../platform/opengl/buffer/UGLVAO.h"
#include "../../platform/opengl/buffer/UGLVertexBuffer.h"
#include "buffers/UBufferLayout.h"

namespace Ursa::Render {

    Ref<GL::UGLVAO> TEMP_VAO;

    URenderPipeline::URenderPipeline() = default;

    URenderPipeline::~URenderPipeline() {
        Terminate();
    }

    void URenderPipeline::Init() {
        GraphicsAPI()->Init();
        m_Window = GraphicsAPI()->CreateWindow({800, 600, "Ursa Engine"});
        m_Renderer = GraphicsAPI()->CreateRenderer(m_Window, m_ShaderLibrary);

        constexpr float vertices[] = {
            -0.5f, -0.5f, 0.0f, // левая вершина
            0.5f, -0.5f, 0.0f, // правая вершина
            0.0f, 0.5f, 0.0f // верхняя вершина
        };

        const UBufferLayout layout({{"a_Position", UElementDataType::FLOAT3}});
        const Ref<UVertexBuffer> vertex_buffer = CreateDerivedRef<UVertexBuffer>(new GL::UGLVertexBuffer(layout, vertices, sizeof(vertices)));
        TEMP_VAO = GL::UGLVAO::Builder().BindVertexBuffer(vertex_buffer).Build();
#ifndef NDEBUG
        GraphicsAPI()->EnableDebug();
#endif
    }

    void URenderPipeline::Terminate() {
        GraphicsAPI()->Terminate();
    }

    void URenderPipeline::Run() const {
        while (!m_Window->ShouldClose()) {
            m_Renderer->Clear();
            TEMP_VAO->Bind();
            m_Renderer->RenderTriangle();
            m_Renderer->Present();
        }
    }

    UGraphicsAPIType URenderPipeline::getAPIType() {
        return UGraphicsAPIType::OPENGL;
    }

    void URenderPipeline::RegisterShader(const std::string &name, const Ref<Shaders::UShaderProgram> &shader) {
        m_ShaderLibrary[name] = shader;
    }
}

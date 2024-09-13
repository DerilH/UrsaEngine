#include <iostream>
#include "core/render/URenderPipeline.h"
#include "platform/opengl/buffer/UGLVAO.h"
#include "platform/opengl/buffer/UGLVertexBuffer.h"
#include "platform/opengl/shaders/UGLShaderProgram.h"


void RunRenderPipeLine() {
    Ursa::Ref<Ursa::Render::URenderPipeline> render_pipeline = Ursa::CreateRef<Ursa::Render::URenderPipeline>();
    render_pipeline->Init();

    const Ursa::Ref<Ursa::Render::Shaders::UShaderProgram> shader_program = Ursa::GL::UGLShaderProgram::Builder().
            FromFile(Ursa::Render::Shaders::VERTEX, "resources/builtin/base_shader.vert").FromFile(
                Ursa::Render::Shaders::FRAGMENT, "resources/builtin/base_shader.frag").compile();
    render_pipeline->RegisterShader("Base", shader_program);
    render_pipeline->Run();
}

int main() {
    std::thread render_thread(RunRenderPipeLine);
    render_thread.join();
    return 0;
}

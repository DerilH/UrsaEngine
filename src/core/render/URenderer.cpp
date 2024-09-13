//
// Created by deril on 9/10/24.
//

#include "URenderer.h"

Ursa::Render::URenderer::URenderer(Ref<UWindow> window, const std::map<std::string, Ref<Shaders::UShaderProgram>> &shaderLibrary) : m_Window(window), m_ShaderLibrary(shaderLibrary) {
}

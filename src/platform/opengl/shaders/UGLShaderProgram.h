//
// Created by deril on 9/9/24.
//
#pragma once
#include "../../../core/render/shaders/UShaderProgram.h"
#include <GL/glew.h>

namespace Ursa::GL {
    class UGLShaderProgram : Render::Shaders::UShaderProgram {
        unsigned int m_ID;
        explicit UGLShaderProgram(const GLuint id) : UShaderProgram(), m_ID(id) {}
    public:
        void Bind() override;
        void Unbind() override;

        void setInt(const std::string &uniform, int value) override;
        void setFloat(const std::string &uniform, float value) override;
        void setFloat2(const std::string &uniform, const glm::vec2 &value) override;
        void setFloat3(const std::string &uniform, const glm::vec3 &value) override;
        void setFloat4(const std::string &uniform, const glm::vec4 &value) override;
        void setMat3(const std::string &uniform, const glm::mat3 &value) override;
        void setMat4(const std::string &uniform, const glm::mat4 &value) override;

        class Builder final : public UShaderProgram::Builder {
            Ref<UShaderProgram> compile() override;
        };
    };
}

//
// Created by deril on 9/9/24.
//
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "UGLShaderProgram.h"
#include "../../../core/logging/Logging.h"

namespace Ursa::GL {
    namespace Util {
        class UGLShader {
        public:
            const int m_id;
            UGLShader(const int type, const std::string& code) : m_id(glCreateShader(type)) {
                const char *c_str = code.c_str();
                glShaderSource(m_id, 1, &c_str, NULL);
                glCompileShader(m_id);
                int success;
                glGetShaderiv(m_id, GL_COMPILE_STATUS, &success);
                if (!success)
                {
                    char infoLog[512];
                    glGetShaderInfoLog(m_id, 512, NULL, infoLog);
                    LOG_ERROR("Shader compilation error");
                    LOG_ERROR(infoLog);
                    throw std::runtime_error("Cannot compile shader");
                }
            }

            void Delete() const {
                glDeleteShader(m_id);
            }
        };
    }

    void UGLShaderProgram::Bind() {
        glUseProgram(m_ID);
    }

    void UGLShaderProgram::Unbind() {
        glUseProgram(0);
    }

    void UGLShaderProgram::setInt(const std::string &uniform, int value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniform1i(loc, value);
    }

    void UGLShaderProgram::setFloat(const std::string &uniform, float value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniform1f(loc, value);
    }

    void UGLShaderProgram::setFloat2(const std::string &uniform, const glm::vec2 &value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniform2f(loc, value.x, value.y);
    }

    void UGLShaderProgram::setFloat3(const std::string &uniform, const glm::vec3 &value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniform3d(loc, value.x, value.y, value.z);
    }

    void UGLShaderProgram::setFloat4(const std::string &uniform, const glm::vec4 &value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniform4f(loc, value.x, value.y, value.z, value.w);
    }

    void UGLShaderProgram::setMat3(const std::string &uniform, const glm::mat3 &value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniformMatrix3fv(loc, 1, GL_FALSE, &value[0][0]);
    }
    void UGLShaderProgram::setMat4(const std::string &uniform, const glm::mat4 &value) {
        const int loc = glGetUniformLocation(m_ID, uniform.c_str());
        glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
    }

    Ref<Render::Shaders::UShaderProgram> UGLShaderProgram::Builder::compile() {
        int programId = glCreateProgram();

        if(!m_Code.contains(Render::Shaders::VERTEX)) {
            throw std::runtime_error("Vertex shader not present");
        }
        const std::string& vCode = m_Code.at(Render::Shaders::UShaderType::VERTEX);
        const auto vertexShader = Util::UGLShader(GL_VERTEX_SHADER, vCode);
        glAttachShader(programId, vertexShader.m_id);

        if(!m_Code.contains(Render::Shaders::FRAGMENT)) {
            throw std::runtime_error("Fragment shader not present");
        }
        const std::string fCode = m_Code.at(Render::Shaders::UShaderType::FRAGMENT);
        const auto fragShader = Util::UGLShader(GL_FRAGMENT_SHADER, fCode);
        glAttachShader(programId, fragShader.m_id);

        const Util::UGLShader* geomShader = nullptr;
        if(m_Code.contains(Render::Shaders::UShaderType::GEOMETRY)) {
            std::string gCode = m_Code.at(Render::Shaders::UShaderType::GEOMETRY);
            const auto shader = Util::UGLShader(GL_GEOMETRY_SHADER, vCode);
            geomShader = &shader;
            glAttachShader(programId, geomShader->m_id);
        }

        glLinkProgram(programId);

        vertexShader.Delete();
        fragShader.Delete();
        if(geomShader) geomShader->Delete();

        int success;
        glGetProgramiv(programId, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(programId, 512, NULL, infoLog);
            LOG_ERROR("Shader program linking error");
            LOG_ERROR(infoLog);
            throw std::runtime_error("Cannot link shader program");
        }
        UShaderProgram* program = new UGLShaderProgram(programId);
        return std::shared_ptr<UShaderProgram>(program);
    }
}

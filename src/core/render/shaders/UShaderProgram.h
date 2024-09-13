//
// Created by deril on 9/9/24.
//

#ifndef USHADERPROGRAM_H
#define USHADERPROGRAM_H
#include <map>
#include <string>
#include <glm/glm.hpp>

#include "UShaderType.h"
#include "../../declarations.h"
#include "../../resources/FileReader.h"

namespace Ursa::Render::Shaders {
    class UShaderProgram {
    protected:
        UShaderProgram() = default;
    public: 
        virtual ~UShaderProgram() = default;

        virtual void Unbind() = 0;
        virtual void Bind() = 0;

        virtual void setInt(const std::string& uniform, int value) = 0;
        virtual void setFloat(const std::string& uniform, float value) = 0;
        virtual void setFloat2(const std::string& uniform, const glm::vec2& value) = 0;
        virtual void setFloat3(const std::string& uniform, const glm::vec3& value) = 0;
        virtual void setFloat4(const std::string& uniform, const glm::vec4& value) = 0;

        virtual void setMat3(const std::string& uniform, const glm::mat3& value) = 0;
        virtual void setMat4(const std::string& uniform, const glm::mat4& value) = 0;

        class Builder {
            protected:
            std::map<UShaderType, std::string> m_Code;
            public:
            virtual ~Builder() = default;

            Builder& FromFile(UShaderType type, const std::string& filePath) {
                const std::string code = Resources::FileReader::readFile(filePath);
                FromString(type, code);
                return *this;
            }

            Builder& FromString(UShaderType type, const std::string& code) {
                assert(!code.empty());
                m_Code.insert({type, code});
                return *this;
            }

            virtual Ref<UShaderProgram> compile() = 0;
        };
    };
}


#endif //USHADERPROGRAM_H

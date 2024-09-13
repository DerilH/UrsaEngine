//
// Created by deril on 9/13/24.
//

#pragma once
#include <GL/glew.h>

namespace Ursa::GL {
    class UGLObject {
    protected:
        explicit UGLObject(const GLuint id) : m_ID(id) {}
        UGLObject(): m_ID(0) {
        }
        GLuint m_ID;
    public:
        virtual ~UGLObject() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
    };
}

//
// Created by deril on 9/13/24.
//

#include "UGLVAO.h"

#include <GL/glew.h>

namespace Ursa::GL {
    UGLVAO::UGLVAO(const GLuint id): UGLObject(id) {
        glCreateVertexArrays(1, &m_ID);
    }

    UGLVAO::~UGLVAO() {
        glDeleteVertexArrays(1, &m_ID);
    }

    void UGLVAO::Bind() const {
        glBindVertexArray(m_ID);
    }

    void UGLVAO::Unbind() const {
        glBindVertexArray(0);
    }

    UGLVAO::Builder::Builder() {
        glCreateVertexArrays(1, &m_ID);
    }

    UGLVAO::Builder& UGLVAO::Builder::BindVertexBuffer(const Ref<Render::UVertexBuffer>& buffer) {
        glBindVertexArray(m_ID);
        buffer->Bind();
        buffer->getLayout().Apply(m_attribIndexOffset);
        buffer->Unbind();
        glBindVertexArray(0);

        m_attribByteOffset += buffer->getLayout().getByteOffset();
        m_attribIndexOffset += buffer->getLayout().getByteOffset();
        return *this;
    }

    UGLVAO::Builder& UGLVAO::Builder::BindIndexBuffer(const Ref<Render::UIndexBuffer>& buffer) {
        glBindVertexArray(m_ID);
        buffer->Bind();
        glBindVertexArray(0);
        return *this;
    }

    Ref<UGLVAO> UGLVAO::Builder::Build() const {
        return std::shared_ptr<UGLVAO>(new UGLVAO(m_ID));
    }
}

//
// Created by deril on 9/13/24.
//

#include "UGLVertexBuffer.h"

namespace Ursa::GL {
    UGLVertexBuffer::UGLVertexBuffer(const Render::UBufferLayout& layout, const void* data, const ptrdiff_t size) : UGLObject(),
        UVertexBuffer(layout, data, size) {
        glGenBuffers(1, &m_ID);
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
        glBufferData(GL_ARRAY_BUFFER, m_Size, m_Internal, GL_STATIC_DRAW);
    }

    UGLVertexBuffer::~UGLVertexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void UGLVertexBuffer::Bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void UGLVertexBuffer::Unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
}

//
// Created by deril on 9/13/24.
//

#include "UGLIndexBuffer.h"

namespace Ursa::GL {

    UGLIndexBuffer::UGLIndexBuffer(const void* data, const ptrdiff_t size) : UGLObject(), UIndexBuffer(data, size) {
        glCreateBuffers(1, &m_ID);
        glBindBuffer(GL_ARRAY_BUFFER, m_ID);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    UGLIndexBuffer::~UGLIndexBuffer() {
        glDeleteBuffers(1, &m_ID);
    }

    void UGLIndexBuffer::Bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
    }

    void UGLIndexBuffer::Unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
}
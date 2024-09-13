//
// Created by deril on 9/13/24.
//

#include "UVertexBuffer.h"

#include <utility>

namespace Ursa::Render {
    UVertexBuffer::UVertexBuffer(UBufferLayout  layout, const void* data, const ptrdiff_t size) : m_Layout(std::move(layout)), m_Internal(data), m_Size(size) {
    }

    UBufferLayout UVertexBuffer::getLayout() const {
        return m_Layout;
    }
}

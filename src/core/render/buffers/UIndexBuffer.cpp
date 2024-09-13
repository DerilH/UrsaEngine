//
// Created by deril on 9/13/24.
//

#include "UIndexBuffer.h"

namespace Ursa::Render {
    UIndexBuffer::UIndexBuffer(const void *data, const ptrdiff_t size) : m_Internal(data), m_Size(size) {
    }

}
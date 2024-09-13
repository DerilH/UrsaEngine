//
// Created by deril on 9/13/24.
//

#pragma once
#include <cstddef>

namespace Ursa::Render {
    class UIndexBuffer {
        const void* m_Internal;
        size_t m_Size;
    public:
        UIndexBuffer(const void* data, ptrdiff_t size);
        virtual ~UIndexBuffer() = default;

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
    };
}

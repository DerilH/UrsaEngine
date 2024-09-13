//
// Created by deril on 9/13/24.
//

#pragma once
#include "UBufferLayout.h"

namespace Ursa::Render {

    class UVertexBuffer {
    protected:
        UBufferLayout m_Layout;
        const void* m_Internal;
        ptrdiff_t m_Size;
    public:
        virtual ~UVertexBuffer() = default;

        UVertexBuffer(UBufferLayout layout, const void* data, ptrdiff_t size);
        UBufferLayout getLayout() const;
        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;
    };
};

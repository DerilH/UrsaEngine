//
// Created by deril on 9/13/24.
//

#pragma once
#include "../UGLObject.h"
#include "../../../core/render/buffers/UVertexBuffer.h"

namespace Ursa::GL {
    class UGLVertexBuffer : UGLObject, public Render::UVertexBuffer {
    public:
        UGLVertexBuffer(const Render::UBufferLayout& layout, const void* data, ptrdiff_t size);
        ~UGLVertexBuffer() override;
        void Bind() const override;
        void Unbind() const override;
    };
}

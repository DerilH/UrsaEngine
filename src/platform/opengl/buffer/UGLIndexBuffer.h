//
// Created by deril on 9/13/24.
//

#pragma once
#include "../UGLObject.h"
#include "../../../core/render/buffers/UIndexBuffer.h"

namespace Ursa::GL {
    class UGLIndexBuffer : UGLObject, Render::UIndexBuffer {
    public:
        UGLIndexBuffer(const void* data, ptrdiff_t size);
        ~UGLIndexBuffer() override;
        void Bind() const override;
        void Unbind() const override;
    };
}

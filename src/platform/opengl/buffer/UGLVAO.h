//
// Created by deril on 9/13/24.
//

#pragma once
#include "../UGLObject.h"
#include "../../../core/declarations.h"
#include "../../../core/render/buffers/UIndexBuffer.h"
#include "../../../core/render/buffers/UVertexBuffer.h"

namespace Ursa::GL {
    class UGLVAO final : UGLObject {
        explicit UGLVAO(GLuint id);

        public:
        void Bind() const override;
        void Unbind() const override;

        ~UGLVAO() override;

        class Builder {
            int m_attribIndexOffset = 0;
            int m_attribByteOffset = 0;
            GLuint m_ID = 0;
        public:
            Builder();
            Builder& BindVertexBuffer(const Ref<Render::UVertexBuffer>& buffer);
            Builder& BindIndexBuffer(const Ref<Render::UIndexBuffer>& buffer);
            [[nodiscard]] Ref<UGLVAO> Build() const;
        };
    };
}

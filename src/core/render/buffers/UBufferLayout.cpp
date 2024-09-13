//
// Created by deril on 9/12/24.
//

#include "UBufferLayout.h"

#include <cassert>
#include <utility>
#include <GL/glew.h>

namespace Ursa::Render {

    UElementDataType::UElementDataType(const int elementsCount, const int baseElementSize, const int glType) : m_Index(COUNTER),
        m_ElementsCount(elementsCount), m_BaseTypeSize(baseElementSize), m_Size(m_ElementsCount * m_BaseTypeSize), m_GLType(glType) {
        COUNTER++;
    }

    int UElementDataType::COUNTER = 0;
    UElementDataType UElementDataType::BOOl = UElementDataType(1, sizeof(bool), GL_BOOL);
    UElementDataType UElementDataType::INT = UElementDataType(1, sizeof(int), GL_INT);
    UElementDataType UElementDataType::INT2 = UElementDataType(2, sizeof(int), GL_INT);
    UElementDataType UElementDataType::INT3 = UElementDataType(3, sizeof(int), GL_INT);
    UElementDataType UElementDataType::INT4 = UElementDataType(4, sizeof(int), GL_INT);
    UElementDataType UElementDataType::FLOAT = UElementDataType(1, sizeof(float));
    UElementDataType UElementDataType::FLOAT2 = UElementDataType(2, sizeof(float));
    UElementDataType UElementDataType::FLOAT3 = UElementDataType(3, sizeof(float));
    UElementDataType UElementDataType::FLOAT4 = UElementDataType(4, sizeof(float));
    UElementDataType UElementDataType::MAT3 = UElementDataType(9, sizeof(float));
    UElementDataType UElementDataType::MAT4 = UElementDataType(16, sizeof(float));

    constexpr UElementDataType::operator int() const {
        return m_Index;
    }

    int UElementDataType::getElementCount() const {
        return m_ElementsCount;
    }

    size_t UElementDataType::getBaseElementSize() const {
        return m_BaseTypeSize;
    }

    size_t UElementDataType::getSize() const {
        return m_Size;
    }

    int UElementDataType::getGLType() const {
        return m_GLType;
    }

    bool UElementDataType::isInteger() const {
        return GL_BYTE <= m_GLType <= GL_UNSIGNED_INT;
    }


    UBufferElement::UBufferElement(std::string name, UElementDataType dataType, size_t offset, bool normalized): m_Name(std::move(name)), m_Normalized(normalized),  m_DataType(dataType), m_Offset(offset) {
    }

    UBufferLayout::UBufferLayout(const std::initializer_list<UBufferElementPrototype>& elements) {
        assert(elements.size() > 0);
        m_Elements.reserve(elements.size());
        unsigned int offset;
        for (const auto &[m_Name, m_DataType, m_Normalized]: elements) {
            m_Elements.emplace_back(m_Name, m_DataType, offset, m_Normalized);
            offset += m_DataType.getSize();
        }
    }

#ifndef NDEBUG
    bool checkVao() {
        int vao = 0;
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vao);
        return vao != 0;
    }
#endif

    /***
     * @returns offset sum of attribs
     */
    void UBufferLayout::Apply(const int indexOffset) {
        assert(checkVao());

        unsigned int offset = 0;
        int i = indexOffset;
        for(const UBufferElement& element : m_Elements) {
            glEnableVertexAttribArray(i);
            if(element.m_DataType.isInteger()) {
                glVertexAttribIPointer(i, element.m_DataType.getElementCount(), element.m_DataType.getGLType(), 0, reinterpret_cast<void *>(element.m_Offset));
            }else {
                glVertexAttribPointer(i, element.m_DataType.getElementCount(), element.m_DataType.getGLType(),  element.m_Normalized, 0, reinterpret_cast<void *>(element.m_Offset));
            }
            i++;
        }
    }

    unsigned int UBufferLayout::getByteOffset() const {
        return m_Elements.back().m_Offset;
    }


    std::vector<UBufferElement>::iterator UBufferLayout::begin() {
        return m_Elements.begin();
    }

    std::vector<UBufferElement>::iterator UBufferLayout::end() {
        return m_Elements.end();
    }

    std::vector<UBufferElement>::const_iterator UBufferLayout::begin() const {
        return m_Elements.begin();
    }

    std::vector<UBufferElement>::const_iterator UBufferLayout::end() const {
        return m_Elements.end();
    }
}

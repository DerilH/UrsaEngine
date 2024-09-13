//
// Created by deril on 9/12/24.
//

#pragma once
#include <functional>
#include <string>
#include <vector>
#include <GL/glew.h>

namespace Ursa::Render {
    class UElementDataType {
        int m_Index;
        int m_ElementsCount;
        size_t m_BaseTypeSize;
        size_t m_Size;
        bool m_GLType;

        static int COUNTER;
        UElementDataType(int elementsCount, int baseElementSize, int glType = GL_FLOAT);
    public:

        explicit constexpr operator int() const;

        int getElementCount() const;

        size_t getBaseElementSize() const;

        size_t getSize() const;

        int getGLType() const;

        bool isInteger() const;

        static UElementDataType BOOl;
        static UElementDataType INT;
        static UElementDataType INT2;
        static UElementDataType INT3;
        static UElementDataType INT4;
        static UElementDataType FLOAT;
        static UElementDataType FLOAT2;
        static UElementDataType FLOAT3;
        static UElementDataType FLOAT4;
        static UElementDataType MAT3;
        static UElementDataType MAT4;
    };

    struct UBufferElementPrototype {
        std::string m_Name;
        UElementDataType m_DataType;
        bool m_Normalized;
    };


    class UBufferElement {
        friend class UBufferLayout;
        std::string m_Name;
        UElementDataType m_DataType;
        size_t m_Offset;
        bool m_Normalized;
    public:
        UBufferElement(std::string  name, UElementDataType dataType, size_t offset, bool normalized = false);
    };

    class UBufferLayout {
        std::vector<UBufferElement> m_Elements;
    public:

        UBufferLayout(const std::initializer_list<UBufferElementPrototype>& elements);

        void Apply(int indexOffset = 0);

        unsigned int getByteOffset() const;

        std::vector<UBufferElement>::iterator begin();
        std::vector<UBufferElement>::iterator end();
        std::vector<UBufferElement>::const_iterator begin() const;
        std::vector<UBufferElement>::const_iterator end() const;
    };
}

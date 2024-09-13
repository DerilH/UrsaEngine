//
// Created by deril on 9/10/24.
//
#pragma once
#include "../../platform/opengl/shaders/UGLShaderProgram.h"

namespace Ursa::Render {
    class UWindow {
    public:
        struct Properties {
            int width, height;
            std::string title;
        };

    protected:
        Properties m_Properties;

        explicit UWindow(Properties properties) : m_Properties(std::move(properties)) {
        }

    public:
        virtual ~UWindow() = default;

        void setSize(const int width, const int height) {
            m_Properties.width = width;
            m_Properties.height = height;
        }

        void setTitle(std::string title) {
            m_Properties.title = std::move(title);
        }

        std::string getTitle() const;

        int getWidth() const;

        int getHeight() const;

        virtual bool ShouldClose() const = 0;
        virtual void SwapBuffers() = 0;
    };
}

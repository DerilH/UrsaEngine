cmake_minimum_required(VERSION 3.30)
project(UrsaEngine)
set(CMAKE_CXX_STANDARD 26)


add_executable(UrsaEngine src/main.cpp
        src/core/render/shaders/UShaderProgram.cpp
        src/core/render/shaders/UShaderProgram.h
        src/core/render/shaders/UShaderType.h
        src/core/render/shaders/UUniform.h
        src/core/declarations.h
        src/platform/opengl/shaders/UGLShaderProgram.cpp
        src/platform/opengl/shaders/UGLShaderProgram.h
        src/core/resources/FileReader.cpp
        src/core/resources/FileReader.h
        src/core/logging/Logging.h
        src/core/render/UGraphicsAPI.h
        src/platform/opengl/UOpengGLAPI.cpp
        src/platform/opengl/UOpengGLAPI.h
        src/core/render/UWindow.h
        src/core/Engine.cpp
        src/core/Engine.h
        src/platform/opengl/UGLWindow.cpp
        src/platform/opengl/UGLWindow.h
        src/core/render/URenderPipeline.cpp
        src/core/render/URenderPipeline.h
        src/core/render/URenderer.cpp
        src/core/render/URenderer.h
        src/platform/opengl/UGLRenderer.cpp
        src/platform/opengl/UGLRenderer.h
        src/core/render/buffers/UBufferLayout.cpp
        src/core/render/buffers/UBufferLayout.h
        src/platform/opengl/buffer/UGLVAO.cpp
        src/platform/opengl/buffer/UGLVAO.h
        src/platform/opengl/UGLObject.h
        src/platform/opengl/buffer/UGLVertexBuffer.cpp
        src/platform/opengl/buffer/UGLVertexBuffer.h
        src/platform/opengl/buffer/UGLIndexBuffer.cpp
        src/platform/opengl/buffer/UGLIndexBuffer.h
        src/core/render/buffers/UVertexBuffer.cpp
        src/core/render/buffers/UVertexBuffer.h
        src/core/render/buffers/UIndexBuffer.cpp
        src/core/render/buffers/UIndexBuffer.h
)

find_package(glfw3 3.4 REQUIRED)
target_link_libraries(UrsaEngine glfw)

find_package(glm REQUIRED)
target_link_libraries(UrsaEngine glm::glm )

find_package(OpenGL REQUIRED)
target_link_libraries(UrsaEngine OpenGL::GL)

find_package(GLEW REQUIRED)
target_link_libraries(UrsaEngine GLEW::glew)

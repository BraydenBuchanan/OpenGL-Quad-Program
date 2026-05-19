cmake_minimum_required(VERSION 3.29.5)
project(OpenGLProgram)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

file(GLOB_RECURSE SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(OpenGLProgram ${SRC_FILES})

add_custom_command(TARGET OpenGLProgram POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/Shader.glsl"
    $<TARGET_FILE_DIR:OpenGLProgram>
)

add_custom_command(TARGET OpenGLProgram POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/glew32.dll"
    $<TARGET_FILE_DIR:OpenGLProgram>
)

target_include_directories(OpenGLProgram PRIVATE 
    "C:/Users/Brayden/source/repos/OpenGL/Dependencies/GLEW/include"
    "C:/Users/Brayden/source/repos/OpenGL/Dependencies/GLFW/include"
)

target_link_libraries(OpenGLProgram PRIVATE 
    "C:/Users/Brayden/source/repos/OpenGL/Dependencies/GLEW/lib/Release/x64/glew32.lib"
    "C:/Users/Brayden/source/repos/OpenGL/Dependencies/GLFW/lib-vc2022/glfw3.lib"
    OpenGL::GL
)
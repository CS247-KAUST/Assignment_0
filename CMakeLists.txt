cmake_minimum_required (VERSION 3.21)
project (assignment)

# Adding compile units to executable
add_executable(${PROJECT_NAME}
        src/CS247_prog.cpp
        src/glslprogram.cpp
        src/glslprogram.cpp)


# Adding common folder
include_directories(common/)

# Set project assignment as startup project in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT assignment)

# C++ Compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Adding glad
add_library(glad common/glad/glad.c)
target_link_libraries(${PROJECT_NAME} glad)

# Adding glfw3
add_subdirectory(common/glfw-3.3 common/glfw-3.3/src)
target_link_libraries(${PROJECT_NAME} glfw)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_11)
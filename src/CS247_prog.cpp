// CS 247 - Scientific Visualization, KAUST
//
// Programming Assignment #0

#include <cstdint>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cassert>

#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>

// framework includes
#include "glslprogram.h"

// window size
const unsigned int gWindowWidth = 512;
const unsigned int gWindowHeight = 512;

// callbacks
// TODO: add callbacks definitions (e.g., framebuffer callback, mouse callback, keyboard callback)


// Checkerboard texture
void makeCheckerBoardImage();
const int checkImageHeight = 64;
const int checkImageWidth = 64;
unsigned char checkImage[checkImageHeight][checkImageWidth][3];

// scene configurations
// TODO: define glsl program, MVP matrices,
//  and any other needed variables and configurations

// glfw error callback
static void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

// make checkerboard texture image
void makeCheckerBoardImage() {
    // TODO: make checkerboard texture
    // Hint:  make n consecutive 0s, then n consecutive 1s .. etc
}

// Texture Parameterization
void initTexture() {
    makeCheckerBoardImage();
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    // set the texture wrapping parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // set texture filtering parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    // load texture to the generated checkerboard
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, checkImageWidth, checkImageHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, checkImage);
}
// init application
// - load application specific data
// - set application specific parameters
// - initialize stuff
bool initApplication(int argc, char **argv)
{

    std::string version((const char *)glGetString(GL_VERSION));
    std::stringstream stream(version);
    unsigned major, minor;
    char dot;

    stream >> major >> dot >> minor;

    assert(dot == '.');
    if (major > 3 || (major == 2 && minor >= 0)) {
        std::cout << "OpenGL Version " << major << "." << minor << std::endl;
    } else {
        std::cout << "The minimum required OpenGL version is not supported on this machine. Supported is only " << major << "." << minor << std::endl;
        return false;
    }

    // default initialization
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glDisable(GL_DEPTH_TEST);

    // viewport
    glViewport(0, 0, gWindowWidth, gWindowHeight);

    // projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    return true;
}


// set up the scene: shaders, VAO, ..etc
void setup() {
    // TODO: Set up glsl programs (you need a vertex shader and a fragment shader)
    // Hint: Use GLSLProgram class or your own solution
    // compile & link the shaders

    // TODO: set up Model, View, Projection (MVP) matrices
    // Hint: use glm library

    // TODO: make a cube
    // Hint: set up a Vertex Buffer Object (VBO) and a Vertex Array Object (VAO)

    // set up the texture
    initTexture();

    // TODO: set up any other needed variables and configurations
}

// render a frame
void render() {
    // TODO: bind the texture
    // TODO: update MVP matrices
    // TODO: add uniforms
    // TODO: use the shader program
    // TODO: render the cube
}

// entry point
int main(int argc, char** argv)
{
    // set glfw error callback
    glfwSetErrorCallback(error_callback);

    // init glfw
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    // init glfw window
    GLFWwindow* window;
    window = glfwCreateWindow(gWindowWidth, gWindowHeight, "CS247 - Scientific Visualization", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // set GLFW callback functions
    // =============================================================================
    // TODO: read up on certain GLFW callbacks which we will need in the future.
    // Get an understanding for what a 'callback' is. Questions you should be able to answer include:
    // What is a callback? When is a callback called? How do you use a callback in your application?
    // What are typical examples for callbacks in the context of graphics applications?
    // Have a look at the following examples:
    //
    // glfwSetKeyCallback(window, YOUR_KEY_CALLBACK);
    // glfwSetFramebufferSizeCallback(window, YOUR_FRAMEBUFFER_CALLBACK);
    // glfwSetMouseButtonCallback(window, YOUR_MOUSEBUTTON_CALLBACK);
    // glfwSetCursorPosCallback(window, YOUR_CURSORPOSCALL_BACK);
    // glfwSetScrollCallback(window, YOUR_SCROLL_CALLBACK);
    // ...

    // Implement mouse and keyboard callbacks!
    // Print information about the events on std::cout
    // =============================================================================

    // make context current (once is sufficient)
    glfwMakeContextCurrent(window);

    // get the frame buffer size
    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    // init the OpenGL API (we need to do this once before any calls to the OpenGL API)
    gladLoadGL();

    // init our application
    if (!initApplication(argc, argv)) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }


    // set up the scene
    setup();

    // start traversing the main loop
    // loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // render one frame
        render();

        // swap front and back buffers
        glfwSwapBuffers(window);

        // poll and process input events (keyboard, mouse, window, ...)
        glfwPollEvents();
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}

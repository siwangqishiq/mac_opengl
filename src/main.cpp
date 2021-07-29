#include <iostream>

#include <GLFW/glfw3.h>

#define GL_SILENCE_DEPRECATION
#include <OpenGL/OpenGL.h>
#include <memory>
#include "App.hpp"
 

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0 , 0 , width , height);
}

static void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
		return;
    }
}

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "你好 世界 Hello World", NULL, NULL);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    // if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    //     std::cout << "Failed to initialize GLAD" << std::endl;
    //     return -1;
    // }

    //todo create instance
    std::shared_ptr<App> app = std::make_shared<App>();
    app->init();

    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        app->tick();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    app->free();

	glfwTerminate();

    return 0;
}
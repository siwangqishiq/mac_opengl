#pragma once

#include "Shader.h"

class App{
private:
    float vertices[3 * 2] = {
        -0.5f , -0.5f,
         0.5f , -0.5f,
         0.0f ,  0.5f 
    };

    Shader shader;

    unsigned int vao;
    unsigned int vbo;
public:
    virtual void init(){
        std::cout << "init" << std::endl;

        std::string vertexSrc = GLSL( 
            layout(location = 0) in vec2 aPos;
            void main(){
                gl_Position = vec4(aPos.x , aPos.y ,0.0 , 1.0);
            }
        );

        std::string fragSrc = GLSL(
            precision mediump float; //
            out vec4 FragColor;
            void main(){
                FragColor = vec4(1.0f , 0.0f , 0.0f , 1.0f);
            }
        );

        shader = Shader::buildGPUProgram(vertexSrc , fragSrc);

        glGenVertexArrays(1 , &vao);
        glGenBuffers(1 , &vbo);

        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER , vbo);
        glBufferData(GL_ARRAY_BUFFER , sizeof(vertices) , vertices , GL_STATIC_DRAW);

        glVertexAttribPointer(0 , 2 , GL_FLOAT , GL_FALSE , 2 * sizeof(float) , (void *)0);
        glEnableVertexAttribArray(0);
    }

    virtual void tick(){
        glClearColor(0.2f , 0.2f , 0.2f ,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        shader.useShader();
    
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLE_FAN , 0 , 3);
    }

    virtual void free(){
        glDeleteVertexArrays(1 , &vao);
        glDeleteBuffers(1 , &vbo);
        std::cout << "destory" << std::endl;
    }
};








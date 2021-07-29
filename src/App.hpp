#pragma once

#include <OpenGL/OpenGL.h>

class App{
private:
    float vertices[(2 + 3) * 3] = {
        
    };
public:
    virtual void init(){
        std::cout << "init" << std::endl;
    }

    virtual void tick(){
        glClearColor(0.2f , 0.2f , 0.2f ,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        
    }

    virtual void free(){
        std::cout << "destory" << std::endl;
    }
};








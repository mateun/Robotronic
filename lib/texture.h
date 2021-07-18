//
// Created by mgrus on 17/07/2021.
//

#ifndef ROBOTRONIC_TEXTURE_H
#define ROBOTRONIC_TEXTURE_H


#include <cstdint>
#include <GL/glew.h>

class Texture {

public:
    Texture(int w, int h);
    void setData(uint8_t* data);
    void use();

protected:
    GLuint _handle=0;
    int _width;
    int _height;

};


#endif //ROBOTRONIC_TEXTURE_H

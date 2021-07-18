//
// Created by mgrus on 17/07/2021.
//

#ifndef ROBOTRONIC_SHADER_H
#define ROBOTRONIC_SHADER_H

#include <glm/glm.hpp>
#include <GL/glew.h>

class Shader {

public:
    virtual void setModelMatrix(glm::mat4 modelMatrix);
    virtual void setViewMatrix(glm::mat4 viewMatrix);
    virtual void setProjectionMatrix(glm::mat4 projectionMatrix);
    void setHandle(GLuint handle);
    void use();


    void setSingleColor(float *color);

    void setUseTexture(bool b);

protected:
    GLuint _shaderHandle;

};


#endif //ROBOTRONIC_SHADER_H

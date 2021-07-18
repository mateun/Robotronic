//
// Created by mgrus on 17/07/2021.
//

#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include <gl/glew.h>


void Shader::setModelMatrix(glm::mat4 modelMatrix) {
    glUniformMatrix4fv(6, 1, false, glm::value_ptr(modelMatrix));

}

void Shader::setViewMatrix(glm::mat4 viewMatrix) {
    glUniformMatrix4fv(7, 1, false, glm::value_ptr(viewMatrix));

}

void Shader::setProjectionMatrix(glm::mat4 projectionMatrix) {
    glUniformMatrix4fv(8, 1, false, glm::value_ptr(projectionMatrix));
}

void Shader::use() {
    glUseProgram(_shaderHandle);

}

void Shader::setHandle(GLuint handle) {
    _shaderHandle = handle;
}

void Shader::setSingleColor(float *color) {
    glUniform4fv(100, 1, color);
}



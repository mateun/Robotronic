//
// Created by mgrus on 04/07/2021.
//

#include "view.h"
#include "vao_factory.h"
#include "shader_factory.h"
#include "screen_context.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <SDL_log.h>


View::View(float* color) {

    _projectionMatrix = glm::ortho<float>(-1, 1, -1, 1, 0.1, 100);
    if (color == nullptr) {
        _color = new float[4];
        _color[0] = 0.4;
        _color[1] = 0.2;
        _color[2] = 0.9;
        _color[3] = 1;
    } else {
        _color = color;
    }

}

void View::drawAtNormalizedCoords(glm::vec2 position, glm::vec2 dimension, glm::vec2 screenSize) {
    ShaderFactory shaderFactory;
    Shader* shader =shaderFactory.getDefault2DShaderObject();

    VAOFactory vaoFactory;
    glBindVertexArray(vaoFactory.getUnitRectVAO());
    shader->use();

    float ar = (float) screenSize.x / screenSize.y;
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1), glm::vec3(dimension.x, dimension.y * ar, 1));
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1), glm::vec3(position.x, position.y, 0));
    glm::mat4 modelMatrix = translationMatrix * scaleMatrix;
    glm::mat4 viewMatrix = glm::lookAt(glm::vec3(0, 0, 0.11), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

    shader->setModelMatrix(modelMatrix);
    shader->setViewMatrix(viewMatrix);
    shader->setProjectionMatrix(_projectionMatrix);
    shader->setSingleColor(_color);

    GLenum err = glGetError();
    if (err != 0) {
        SDL_Log("error: %d", err);
    }

    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}


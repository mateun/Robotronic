//
// Created by mgrus on 04/07/2021.
// A View represents a recangular area which can
// be rendered on the screen.
// It is the basis for more sophisticated
// things such as buttons, textboxes, labels, etc.
// In its simplest form it just is a colored rectangle
// on the screen.
//

#ifndef ROBOTRONIC_VIEW_H
#define ROBOTRONIC_VIEW_H

#include <glm/glm.hpp>
#include <GL/glew.h>
#include "texture.h"

class View {

public:
    View(float* color);
    View(Texture* texture);
    void drawAtNormalizedCoords(glm::vec3 position, glm::vec2 dimension, glm::vec2 screenSize);


private:
    float* _color;
    Texture* _texture = nullptr;
    glm::mat4 _projectionMatrix;

    void initProjectionMatrx();
};


#endif //ROBOTRONIC_VIEW_H

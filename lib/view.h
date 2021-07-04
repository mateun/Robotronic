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

class View {

public:
    View(float* color);
    void drawAtNormalizedCoords(glm::vec2 position, glm::vec2 dimension);


private:
    float* _color;
    glm::mat4 _projectionMatrix;
};


#endif //ROBOTRONIC_VIEW_H
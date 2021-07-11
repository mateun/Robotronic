//
// Created by mgrus on 04/07/2021.
//


#include "vao_factory.h"
#include "SDL.h"
#include "timer.h"

GLuint VAOFactory::_unitRectVAO = 0;

GLuint VAOFactory::getUnitRectVAO() {
    if (_unitRectVAO == 0) {
        initUnitRectVAO();
    }

    return _unitRectVAO;
}

void VAOFactory::initOrthoGridVAO() {
    glGenVertexArrays(1, &_unitRectVAO);
    glBindVertexArray(_unitRectVAO);

    GLuint vboPos;
    float positions[] = {
            0, 1,  0. ,   // top left
            0, 0,  0. ,  // bottom left
            1, 0,    0,   // bottom right
            1, 1, 0        // top right
    };

    int numberOfLines = 10;
    int numberOfComponents = 3;
    for (int i = 0; i < numberOfLines * numberOfComponents; i++) {
      //  positions[i] =
    }

    glGenBuffers(1, &vboPos);
    glBindBuffer(GL_ARRAY_BUFFER, vboPos);
    glBufferData(GL_ARRAY_BUFFER, 12*4, positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    GLuint indices[] = {
            0, 1, 2, 0, 2, 3
    };

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*4, indices, GL_STATIC_DRAW);
    glBindVertexArray(0);
}


void VAOFactory::initUnitRectVAO() {
    glGenVertexArrays(1, &_unitRectVAO);
    glBindVertexArray(_unitRectVAO);

    GLuint vboPos;
    float positions[] = {
            0, 1,  0. ,   // top left
            0, 0,  0. ,  // bottom left
            1, 0,    0,   // bottom right
            1, 1, 0        // top right
    };
    glGenBuffers(1, &vboPos);
    glBindBuffer(GL_ARRAY_BUFFER, vboPos);
    glBufferData(GL_ARRAY_BUFFER, 12*4, positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(0);

    GLuint indices[] = {
        0, 1, 2, 0, 2, 3
    };

    GLuint ibo;
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 6*4, indices, GL_STATIC_DRAW);
    glBindVertexArray(0);


}


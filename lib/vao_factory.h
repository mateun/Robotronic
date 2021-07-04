//
// Created by mgrus on 04/07/2021.
// This class provides access to
// standard VAOs which should be reused, e.g.
// for unit rects, unit cubes etc.
//

#ifndef ROBOTRONIC_VAO_FACTORY_H
#define ROBOTRONIC_VAO_FACTORY_H

#include <GL/glew.h>

class VAOFactory {

public:
    GLuint getUnitRectVAO();
    GLuint getOrthoGridVAO();

private:
    // The pivot point is at the lower left corner.
    void initUnitRectVAO();
    void initOrthoGridVAO();


private:
    static GLuint _unitRectVAO;
    static GLuint _orthoGridVAO;

};

#endif //ROBOTRONIC_VAO_FACTORY_H

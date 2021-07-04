//
// Created by mgrus on 04/07/2021.
//

#include <GL/glew.h>
#include <cstdlib>
#include "RobotronicGame.h"

void RobotronicGame::init() {
    GLenum r = glewInit();
    if (r != GLEW_OK) {
        exit(1)
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void RobotronicGame::shutdown() {

}

void RobotronicGame::update(float frameTimeInSeconds) {

}

void RobotronicGame::render(float frameTimeInSeconds) {

}




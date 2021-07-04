//
// Created by mgrus on 04/07/2021.
//

#include <GL/glew.h>
#include <cstdlib>
#include "RobotronicGame.h"

extern void stopGame();

void RobotronicGame::init() {
    startButton = new View(new float[]{0.3, 0.9, 0.4, 1});
    settingsButton = new View(new float[] { 0.5, 0.1, 0.2, 1});
    exitButton = new View(new float[] { 0.5, 0.5, 0.2, 1});
}

void RobotronicGame::shutdown() {

}

void RobotronicGame::update(float frameTimeInSeconds, const std::vector<SDL_Event>& frameEvents) {
    for (auto fe : frameEvents) {
        if (fe.type == SDL_KEYDOWN) {
            if (fe.key.keysym.sym = SDLK_ESCAPE) {
                stopGame();
            }
        }
    }
}

void RobotronicGame::render(float frameTimeInSeconds) {
    startButton->drawAtNormalizedCoords(glm::vec2 {-0.5, -0.25}, glm::vec2(1, 0.5));
    exitButton->drawAtNormalizedCoords(glm::vec2 {-1, 0.75}, glm::vec2(0.25, 0.25));
    settingsButton->drawAtNormalizedCoords(glm::vec2 {0.75, -1}, glm::vec2(0.25, 0.25));
}

void RobotronicGame::preRender() {
    glClearColor(0.1, 0.2, 0.7, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}




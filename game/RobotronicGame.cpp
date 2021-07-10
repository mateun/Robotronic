//
// Created by mgrus on 04/07/2021.
//

#include <GL/glew.h>
#include <cstdlib>
#include "RobotronicGame.h"

extern void stopGame();

RobotronicGame::RobotronicGame() {
    screenWidth = 1024;
    screenHeight = 768;
}

void RobotronicGame::init() {
    startButton = new View(new float[]{0.03, 0.9, 0.04, 1});
    settingsButton = new View(new float[] { 0.9, 0.01, 0.02, 1});
    exitButton = new View(new float[] { 0.9, 0.95, 0.9, 1});
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

    heightValue += 0.0005;
    heightSine = sin(heightValue);
}

void RobotronicGame::render(float frameTimeInSeconds) {
    //startButton->drawAtNormalizedCoords(glm::vec2 {-0.5, -0.25}, glm::vec2(1, 0.5));
    glm::vec2 screenSize { screenWidth, screenHeight};
    exitButton->drawAtNormalizedCoords(glm::vec2 {-0.5, heightSine}, glm::vec2(1, 0.25), screenSize);
    settingsButton->drawAtNormalizedCoords(glm::vec2 {0.75, -1}, glm::vec2(1.5, 0.25), screenSize);
}

void RobotronicGame::preRender() {
    glClearColor(0.01, 0.02, 0.0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}




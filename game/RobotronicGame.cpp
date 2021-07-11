//
// Created by mgrus on 04/07/2021.
//

#include <GL/glew.h>
#include <cstdlib>
#include "RobotronicGame.h"
#include "../lib/shader_factory.h"

extern void stopGame();

RobotronicGame::RobotronicGame() {
    screenWidth = 1920;
    screenHeight = 1080;
    playerPos = glm::vec2(-0.25, 0.25);
    playerVelocity = glm::vec2{0,0};


}

void RobotronicGame::init() {
    player = new View(new float[]{0.7, 0.7, 0.04, 1});
    firstPlatform = new View(new float[] {0.3, 0.2, 0.3, 1});
    secondPlatform = new View(new float[] {0.3, 0.2, 0.3, 1});

    // Warm up the shaderfactory
    ShaderFactory shaderFactory;
    shaderFactory.getDefault2DShader();
}

void RobotronicGame::shutdown() {

}

void RobotronicGame::updatePlayerPos(float frameTime) {
    frame++;
    SDL_Log("frame: %d ft: %f", frame, frameTime);
    // Let gravity be -0.1 units per second
    float gravity = -0.0001;
    playerAcceleration.y = gravity * frameTime;
    playerAcceleration.x = 0;
    playerVelocity += playerAcceleration;
    playerPos += playerVelocity;
}

void RobotronicGame::update(float frameTimeInSeconds, const std::vector<SDL_Event>& frameEvents) {
    for (auto fe : frameEvents) {
        if (fe.type == SDL_KEYDOWN) {
            if (fe.key.keysym.sym == SDLK_ESCAPE) {
                stopGame();
            }
            if (fe.key.keysym.sym == SDLK_r) {
                playerPos = glm::vec2{-0.25, .25};
                playerVelocity = {0, 0};
            }
        }
    }

    updatePlayerPos(frameTimeInSeconds);

    //SDL_Log("frameTime: %f", frameTimeInSeconds);
    heightValue += 5 * frameTimeInSeconds;
    //heightSine = sin(heightValue);
}

void RobotronicGame::render(float frameTimeInSeconds) {
    glm::vec2 screenSize { screenWidth, screenHeight};
    player->drawAtNormalizedCoords(playerPos, glm::vec2(0.04, 0.1), screenSize);
    firstPlatform->drawAtNormalizedCoords(glm::vec2 {-1, -1}, glm::vec2(0.8, 0.25), screenSize);
    secondPlatform->drawAtNormalizedCoords(glm::vec2 {0, -1}, glm::vec2(1, 0.25), screenSize);

}

void RobotronicGame::preRender() {
    glClearColor(0.01, 0.02, 0.0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}




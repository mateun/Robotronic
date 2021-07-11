//
// Created by mgrus on 04/07/2021.
//

#include <GL/glew.h>
#include <cstdlib>
#include "RobotronicGame.h"
#include "../lib/shader_factory.h"

#include "../lib/imgui/imgui.h"
#include "../lib/imgui/imgui_impl_sdl.h"
#include "../lib/imgui/imgui_impl_opengl3.h"
#include "../lib/vao_factory.h"


extern void stopGame();

RobotronicGame::RobotronicGame() {
    screenWidth = 1920;
    screenHeight = 1080;
    playerPos = glm::vec2(-0.9, -0.0);
    playerVelocity = glm::vec2{0,0};
    playerJumpAcceleration = glm::vec2(0, 0);

    float ar = (float) screenWidth / screenHeight;
    platformData[0].position = {-1, -1};
    platformData[0].dimension = {0.8, 0.25};
    platformData[0].topEdgeY = platformData[0].position.y + platformData->dimension.y * ar;
    platformData[1].position = {0, -1};
    platformData[1].dimension = {1, 0.25};
    platformData[1].topEdgeY = platformData[1].position.y + platformData->dimension.y * ar;

}

void RobotronicGame::init() {
    player = new View(new float[]{0.7, 0.7, 0.04, 1});
    firstPlatform = new View(new float[] {0.3, 0.2, 0.3, 1});
    secondPlatform = new View(new float[] {0.3, 0.2, 0.3, 1});

    //orthoGridVAO = VAOFactory::getOrthoGridVAO();

    // Warm up the shaderfactory
    ShaderFactory shaderFactory;
    shaderFactory.getDefault2DShader();


}

void RobotronicGame::shutdown() {

}

void RobotronicGame::updatePlayerPos(float frameTime) {
    frame++;

    float gravity = -0.001;
    float jumpy = 0;
    if (isJumping) {
        playerJumpAcceleration.y += (gravity*10000 * frameTime);
        if (playerJumpAcceleration.y < 0) {
            playerJumpAcceleration.y = 0;
        }
    }

    playerAcceleration.y = (playerJumpAcceleration.y + gravity) * frameTime;
    playerAcceleration.x = 0;
    playerVelocity += playerAcceleration;
    playerPos += playerVelocity;

    float ar = (float) screenWidth / screenHeight;

    for (auto data : platformData) {

        if ((playerPos.y) < data.topEdgeY ) {
            playerPos.y = data.topEdgeY;
            playerVelocity.y = 0;
            isJumping = false;
            break;
        }
    }

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

            if (fe.key.keysym.sym == SDLK_s) {
                singleStepMode = !singleStepMode;
                SDL_Log("Switch single stepMode: %d", singleStepMode);
            }

            if (fe.key.keysym.sym == SDLK_SPACE) {
                spacePressed = true;
            }

            if (fe.key.keysym.sym == SDLK_j) {
                if (isJumping == false) {
                    isJumping = true;
                    playerJumpAcceleration = glm::vec2(0, 0.38);
                }

            }
        }
    }

    if (singleStepMode && spacePressed) {
        updatePlayerPos(2);
        spacePressed = false;
    } else if (!singleStepMode){
        updatePlayerPos(frameTimeInSeconds);
    }

}

void RobotronicGame::render(float frameTimeInSeconds) {
    glm::vec2 screenSize { screenWidth, screenHeight};
    player->drawAtNormalizedCoords(playerPos, glm::vec2(0.07, 0.1), screenSize);

    for (int i = 0; i < 5; i++) {
        player->drawAtNormalizedCoords(glm::vec2(i*.1, i * .1), glm::vec2(0.1, 0.1), screenSize);
    }


    firstPlatform->drawAtNormalizedCoords(platformData[0].position, platformData[0].dimension, screenSize);
    secondPlatform->drawAtNormalizedCoords(platformData[1].position, platformData[1].dimension, screenSize);

    ImGui::Begin("Player debug info");   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
    ImGui::Text("PlayerPos: %f/%f", playerPos.x, playerPos.y);
    ImGui::Text("frameTime: %f", frameTimeInSeconds);
    ImGui::Text("PlayerAcc: %f/%f", playerAcceleration.x, playerAcceleration.y);
    ImGui::Text("PlayerVel: %f/%f", playerVelocity.x, playerVelocity.y);
    ImGui::Text("PlayerJumpAcc.: %f", playerJumpAcceleration.y);
    ImGui::Text("isJumping.: %d", isJumping);
    ImGui::Text("Platform topEdge: %f", platformData[0].topEdgeY);
    ImGui::End();


}

void RobotronicGame::preRender() {
    glClearColor(0.01, 0.02, 0.0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}




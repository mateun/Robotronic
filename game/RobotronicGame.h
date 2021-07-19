//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_ROBOTRONICGAME_H
#define ROBOTRONIC_ROBOTRONICGAME_H
#include "../lib/game.h"
#include "../lib/view.h"
#include <SDL.h>
#include <vector>
#include <glm/glm.hpp>


class Platform {
public:
    glm::vec3 position;
    glm::vec2 dimension;
    float topEdgeY = 0;
};

class RobotronicGame : public Game {


public:
    RobotronicGame();

public:

    void update(float frameTimeInSeconds, const std::vector<SDL_Event>& frameEvents) override;
    void render(float frameTimeInSeconds) override;
    void init() override;
    void shutdown() override;
    void preRender() override;


private:
    void updatePlayerPos(float frameTime);



private:
    View* player;
    View* secondPlatform;
    View* firstPlatform;
    View* grassTile;

    GLuint orthoGridVAO;

    float heightSine = 0;
    float heightValue = 0;
    glm::vec3 playerAcceleration;
    glm::vec3 playerJumpAcceleration;
    glm::vec3 playerVelocity;
    glm::vec3 playerPos;
    int frame = 0;
    bool isJumping = false;

    Platform platformData[2];

    bool singleStepMode = true;
    bool spacePressed = false;

    Texture* _heroTexture;
    Texture* _greenTileTexture;



};


#endif //ROBOTRONIC_ROBOTRONICGAME_H

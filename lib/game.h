//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_GAME_H
#define ROBOTRONIC_GAME_H
#include <vector>
#include <SDL.h>

class Game {

public:
    virtual void init() = 0;
    virtual void update(float frameTimeInSeconds, const std::vector<SDL_Event>& frameEvents) = 0;
    virtual void preRender() = 0;
    virtual void render(float frameTimeInSeconds) = 0;
    virtual void shutdown() = 0;

    int getScreenWidth() { return screenWidth;}
    int getScreenHeight() { return screenHeight;}

protected:
    int screenWidth;
    int screenHeight;
};

#endif //ROBOTRONIC_GAME_H

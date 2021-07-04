//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_GAME_H
#define ROBOTRONIC_GAME_H

class Game {

public:
    virtual void init() = 0;
    virtual void update(float frameTimeInSeconds) = 0;
    virtual void preRender() = 0;
    virtual void render(float frameTimeInSeconds) = 0;
    virtual void shutdown() = 0;
};

#endif //ROBOTRONIC_GAME_H

//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_ROBOTRONICGAME_H
#define ROBOTRONIC_ROBOTRONICGAME_H
#include "../lib/game.h"

class RobotronicGame : public Game {

    void update(float frameTimeInSeconds) override;
    void render(float frameTimeInSeconds) override;
    void init() override;
    void shutdown() override;
};

#endif //ROBOTRONIC_ROBOTRONICGAME_H

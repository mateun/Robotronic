//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_ROBOTRONICGAME_H
#define ROBOTRONIC_ROBOTRONICGAME_H
#include "../lib/game.h"
#include "../lib/view.h"
#include <SDL.h>
#include <vector>

class RobotronicGame : public Game {

    void update(float frameTimeInSeconds, const std::vector<SDL_Event>& frameEvents) override;
    void render(float frameTimeInSeconds) override;
    void init() override;
    void shutdown() override;
    void preRender() override;

private:
    View* startButton;
    View* exitButton;
    View* settingsButton;
};

#endif //ROBOTRONIC_ROBOTRONICGAME_H

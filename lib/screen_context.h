//
// Created by mgrus on 04/07/2021.
//

#ifndef ROBOTRONIC_SCREEN_CONTEXT_H
#define ROBOTRONIC_SCREEN_CONTEXT_H

class ScreenContext {
public:
    ScreenContext() {};
    ScreenContext(int w, int h);
    int getScreenWidth();
    int getScreenHeight();

private:
    static int _width;
    static int _height;
};

#endif //ROBOTRONIC_SCREEN_CONTEXT_H

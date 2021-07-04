//
// Created by mgrus on 04/07/2021.
//

#include "screen_context.h"

int ScreenContext::_width = 0;
int ScreenContext::_height = 0;

ScreenContext::ScreenContext(int w, int h)  {
    _width = w;
    _height = h;
}

int ScreenContext::getScreenHeight() {
    return _height;
}

int ScreenContext::getScreenWidth() {
    return _width;
}


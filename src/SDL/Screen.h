#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include "Surface.h"
#include "Rect.h"
#include <iostream>
#include <string>

class Screen {
public:
    Screen(std::string name, int x=100, int y=100, int w=640, int h=480,
           int flags_win=SDL_WINDOW_SHOWN, int flags_ren=SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    ~Screen();
    void clear();
    void texture(Surface & s) const;
    void draw(Surface & s);
    void draw(Surface & s, Rect & src);
    void draw(Surface & s, Rect & src, Rect & dest);
    void update();
private:
    SDL_Window * win_;
    SDL_Renderer * ren_;
};

#endif

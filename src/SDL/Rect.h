#ifndef RECT_H
#define RECT_H

#include "SDL.h"

class Rect {
public:
    Rect(int x=0, int y=0, int w=0, int h=0);
    int x() {return r_.x;}
    int y() {return r_.y;}
    int w() {return r_.w;}
    int h() {return r_.h;}

    void set_x(int x) {r_.x = x;}
    void set_y(int y) {r_.y = y;}
    void set_w(int w) {r_.w = w;}
    void set_h(int h) {r_.h = h;}

    SDL_Rect * get_addr() {return &r_;}
    SDL_Rect get_self() {return r_;}
private:
    SDL_Rect r_;
};

#endif

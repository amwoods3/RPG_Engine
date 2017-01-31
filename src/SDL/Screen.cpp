#include "Screen.h"

Screen::Screen(std::string name, int x, int y, int w, int h,
               int flags_win, int flags_ren)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
    }
    win_ = SDL_CreateWindow(name.c_str(), x, y, w, h, flags_win);
    if (win_ == NULL) {
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
    }
    ren_ = SDL_CreateRenderer(win_, -1, flags_ren);
    if (ren_ == NULL) {
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
    }
}

Screen::~Screen() {
    SDL_DestroyRenderer(ren_);
    SDL_DestroyWindow(win_);
    SDL_Quit();
}

void Screen::clear() {
    SDL_RenderClear(ren_);
}

void Screen::texture(Surface & s) const {
    if (s.get_texture() == NULL) {
        s.set_texture(SDL_CreateTextureFromSurface(ren_, s.get_surface()));
    }
}

void Screen::draw(Surface & s) {
    texture(s);
    SDL_RenderCopy(ren_, s.get_texture(), NULL, NULL);
}

void Screen::draw(Surface & s, Rect & src) {
    texture(s);
    SDL_RenderCopy(ren_, s.get_texture(), src.get_addr(), NULL);
}

void Screen::draw(Surface & s, Rect & src, Rect & dest) {
    texture(s);
    SDL_RenderCopy(ren_, s.get_texture(), src.get_addr(), dest.get_addr());
}

void Screen::update() {
    SDL_RenderPresent(ren_);
}

#include "Text.h"
#include "Screen.h"

#include <iostream>

Text::Text(const std::string & text, int size, const char font[], SDL_Color color,
           int x, int y, Screen & screen)
    : text_(text), size_(size), color_(color)
{
    font_ = TTF_OpenFont(font, size_);
    if (font_ == NULL) {
        printf("No Font! SDL_ttf Error: %s\n", TTF_GetError());
    }
    update(screen);
}

void Text::update(Screen & screen) {
    surface_.change_surface(TTF_RenderText_Solid(font_, text_.c_str(), color_));
    screen.texture(surface_);
}

void Text::initialize() {
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
    }
    return;
}

void Text::draw(Screen & s) {
    s.draw(surface_);
}

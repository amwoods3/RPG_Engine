#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "SDL.h"
#include "Rect.h"
#include "Screen.h"
#include "Surface.h"
#include "SDL_ttf.h"

class Text {
public:
    Text(const std::string & text, int size, const char font[], SDL_Color color,
         int x, int y, Screen & screen);
    //Text(const std::string & text, int size, const std::string & font,
    //     SDL_Color color, int x, int y);

    void free();
    void draw(Screen & screen);
    void update(Screen &);
    static void initialize();
private:
    std::string text_;
    int size_;
    TTF_Font * font_;
    SDL_Color color_;
    Rect rect_;
    Surface surface_;
};


#endif

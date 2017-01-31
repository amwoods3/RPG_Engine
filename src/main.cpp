#include <iostream>
#include "StateFactory.h"
#include "StateStack.h"
#include "Screen.h"
#include "Surface.h"
#include "Rect.h"
#include "Text.h"

int main()
{
    Screen game_screen("This is a test");
    Surface test("img/Bubble_Mountain.png");
    Surface logo("img/Etchville_logo.png");
    SDL_Color blue = {0, 0, 255};
    Text::initialize();
    std::cout << "Making a Text object" << std::endl;
    Text test_string("I am testing my text", 12, "sans.ttf", blue, 100, 100,
                     game_screen);
    std::cout << "Finished Making a Text object" << std::endl;
    Rect src(31, 236, 1501, 673);
    Rect dest(100, 100, 400, 200);
    for (int i = 0; i < 3; ++i) {
        game_screen.clear();
        game_screen.draw(test);
        game_screen.draw(logo, src, dest);
        test_string.draw(game_screen);
        game_screen.update();
        SDL_Delay(1000);
    }
    return 0;
}

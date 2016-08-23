#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include "AbstractState.h"

#define NEW_GAME 1
#define BATTLE 2
#define QUIT 0
#define MAIN_MENU_STATE 0

class MainMenuState: public AbstractState {
public:
    MainMenuState() : AbstractState(MAIN_MENU_STATE) {
        onEnter();
    }
    
    void render() {
        
    }
    
    void update(float elapsedTime) {
        int choice = 0;
        std::cin >> choice;
        set_input(choice);
        if (choice == QUIT) {
            onExit();
        }
    }
    
    void onEnter() {
        std::cout << "Hello, World!" << std::endl;
    }
    
    void onExit() {
        std::cout << "Thank you for playing! Good Night!" << std::endl;
        finish();
    }
};
#endif

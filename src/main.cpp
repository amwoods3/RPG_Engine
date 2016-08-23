#include <iostream>
#include "StateFactory.h"
#include "StateStack.h"

int main()
{
    StateStack game;
    StateFactory state_manager;
    state_manager.updateState(game);
    while (true) {
        state_manager.updateState(game);
        game.update(0.4);
        if (!game.running()) break;
        game.render();
    }
    return 0;
}

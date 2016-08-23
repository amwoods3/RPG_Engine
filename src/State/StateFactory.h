#ifndef STATE_FACTORY_H
#define STATE_FACTORY_H

#include "AbstractState.h"
#include "StateStack.h"
#include "MainMenuState.h"
#include "BattleState.h"

class StateFactory {
public:
    void updateState(StateStack & ss) {
        if (!ss.running()) {
            ss.push(new MainMenuState);
        }
        if (ss.state() == MAIN_MENU_STATE) {
            get_next_state_main_menu(ss);
        }
    }

    void get_next_state_main_menu(StateStack & ss) {
        switch (ss.input()) {
        case NO_INPUT:
            break;
        case NEW_GAME:
            break;
        case BATTLE:
            ss.push(new BattleState);
            break;
        }
    }
    
private:
};

#endif

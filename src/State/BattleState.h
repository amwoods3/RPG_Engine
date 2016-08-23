#ifndef BATTLE_STATE_H
#define BATTLE_STATE_H

#include "AbstractState.h"

#define BATTLE_STATE 16

class BattleState : public AbstractState {
public:
    BattleState(): AbstractState(BATTLE_STATE) {
        onEnter();
    }
    void render() {
        char c;
        std::cin >> c;
        if (c == 'd') {
            onExit();
        }
    }

    void update(float elapseTime) {
        std::cout << "In the battle state! Enter 'd' to finish fight!\n";
    }

    void onEnter() {
        std::cout << "Entering Battle!\nTransform the screen and queue the battle music.\n";
    }

    void onExit() {
        std::cout << "Battle over, if lost queue sad game over music, fade out."
                  << std::endl
                  << "If we won, queue the victory music, and rewards screen."
                  << std::endl;
        finish();
    }
    
};
#endif

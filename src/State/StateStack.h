#ifndef STATESTACK_H
#define STATESTACK_H

#include "Stack.h"


class StateStack {
public:
    void update(float elapseTime) {
        gameStateStack.top()->update(elapseTime);
        if (gameStateStack.top()->is_finished()) {
            pop();
        }
    }

    void render() {
        gameStateStack.top()->render();
    }
    
    void push(AbstractState * state) {
        if (running()) {
            gameStateStack.top()->set_input(NO_INPUT);
        }
        gameStateStack.push(state);
    }

    void pop() {
        gameStateStack.pop();
    }

    bool running() {
        return !gameStateStack.empty();
    }

    int input() {
        return gameStateStack.top()->get_input();
    }

    int state() {
        return gameStateStack.top()->get_state();
    }
private:
    Stack gameStateStack;
};


#endif

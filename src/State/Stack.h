#ifndef STACK_H
#define STACK_H

#include "AbstractState.h"
#include "LinkedList.h"

class Stack {
public:
    Stack() {}
    Stack(AbstractState * state): s_(state){}
    Stack(AbstractState * state[], int size): s_(state, size) {}
    Stack(const Stack & other): s_(other.s_) {}
    Stack(const LinkedList & l): s_(l) {}

    void push(AbstractState * state) {s_.insert_front(state);}
    void pop() {return s_.remove_front();}
    AbstractState * top() {return s_.front();}
    bool empty() {return s_.empty();}
private:
    LinkedList s_;
};

#endif

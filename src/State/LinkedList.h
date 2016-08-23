#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "AbstractState.h"

class LinkedListNode {
public:
    LinkedListNode(AbstractState * state)
        : state_(state)
    {
        next_ = 0;
    }

    AbstractState * state() const {return state_;}
    void set_state(AbstractState * state) {state_ = state;}

    LinkedListNode * next() const {return next_;}
    void set_next(LinkedListNode * next) {next_ = next;}
private:
    LinkedListNode * next_;
    AbstractState * state_;
};


class LinkedList {
public:
    LinkedList(); // create an empty linked list
    LinkedList(AbstractState * state);  // create a single state linked list
    LinkedList(AbstractState * states[], int size); // Copy the data from array to linked list
    LinkedList(const LinkedList & l); // Copy the data to a new linked list
    ~LinkedList();
    void insert_back(AbstractState * state);
    void insert_front(AbstractState * state);
    void remove_back();
    void remove_front();
    AbstractState * front() const {return head_->state();}
    AbstractState * back() const {return tail_->state();}
    bool empty() const;

    LinkedListNode * head() const {return head_;}
    LinkedListNode * tail() const {return tail_;}
    
    
private:
    void empty_insert(AbstractState * state);
    LinkedListNode * head_;
    LinkedListNode * tail_;
};
#endif

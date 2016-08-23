#include "LinkedList.h"
#include <exception>

LinkedList::LinkedList()
    : head_(0), tail_(0)
{
}

LinkedList::LinkedList(AbstractState * state)
    : head_(0), tail_(0)
{
    insert_back(state);
}

LinkedList::LinkedList(AbstractState * state[], int size)
    : head_(0), tail_(0)
{
    for (int i = 0; i < size; ++i) {
        insert_back(state[i]);
    }
}

LinkedList::LinkedList(const LinkedList & l)
    : head_(0), tail_(0)
{
    LinkedListNode * toInsert = l.head();
    while (toInsert != 0) {
        insert_back(toInsert->state());
        toInsert = toInsert->next();
    }
}

LinkedList::~LinkedList() {
    LinkedListNode * toDelete = head();
    while (toDelete != 0) {
    head_ = head()->next();
    delete toDelete;
    toDelete = head();
    }
}

void LinkedList::insert_back(AbstractState * state) {
    if (empty()) {
        empty_insert(state);
        return;
    }
    LinkedListNode * back = new LinkedListNode(state);
    tail_->set_next(back);
    tail_ = back;
    return;
}

void LinkedList::insert_front(AbstractState * state) {
    if (empty()) {
        empty_insert(state);
        return;
    }
    LinkedListNode * front = new LinkedListNode(state);
    front->set_next(head());
    head_ = front;
}

void LinkedList::remove_back() {
    if (empty()) {
        std::out_of_range e("List empty!");
        throw e;
    }
    LinkedListNode * toDelete = tail();
    LinkedListNode * next_tail = head();
    while (next_tail->next() != tail())
        next_tail = next_tail->next();
    tail_ = next_tail;
    tail_->set_next(0);
    delete toDelete;
}

void LinkedList::remove_front() {
    if (empty()) {
        std::out_of_range e("List empty!");
        throw e;
    }
    LinkedListNode * toDelete = head();
    head_ = head()->next();
    delete toDelete;
}

void LinkedList::empty_insert(AbstractState * state) {
    head_ = new LinkedListNode(state);
    tail_ = head_;
}

bool LinkedList::empty() const {
    return (head_ == 0);
}

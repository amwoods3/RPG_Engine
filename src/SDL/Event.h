#ifndef EVENT_H
#define EVENT_H

#include "SDL.h"

class Event {
public:
    void get_event();
    
private:
    SDL_Event event_;
};

#endif


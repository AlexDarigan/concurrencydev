/*! \class Event
    \brief A simple event that consumes an integer
*/

#include "Event.h"

/**
    \param num The event number
    \return Event
*/
Event::Event(int num) {
    number = num;
}

/**
    \return number, the event number
*/
int Event::consume() {
    return number;
}

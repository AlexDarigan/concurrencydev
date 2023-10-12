#include "Event.h"

Event::Event(int num) {
    number = num;
}

int Event::consume() {
    return number;
}

#include "Event.h"

Event::Event(char alpha) {
    lowercase = alpha;
}

void Event::Process() {
    uppercase = lowercase - 32;
}

char Event::getUpper() {
    return uppercase;
}
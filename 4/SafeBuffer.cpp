#include "SafeBuffer.h"
#include "Event.h"
#include <memory>

template <typename T>
SafeBuffer<T>::SafeBuffer(int size) {

}

template <typename T>
void SafeBuffer<T>::put(T element) {
    
}

template <typename T>
T SafeBuffer<T>::get() {
    return placeholder;
}

// I hate this
template class SafeBuffer<std::shared_ptr<Event>>;

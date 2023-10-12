#include "SafeBuffer.h"
#include "Event.h"
#include <memory>

template <typename T>
SafeBuffer<T>::SafeBuffer(int size) {
    mutex = std::make_shared<Semaphore>(1);
    items = std::make_shared<Semaphore>(0);
}

template <typename T>
void SafeBuffer<T>::put(T element) {
    mutex->Wait();
    queue.push(element);
    mutex->Signal();
    items->Signal();
}

template <typename T>
T SafeBuffer<T>::get() {
    mutex->Wait();
    // get item
    T element = queue.front();
    queue.pop();
    items->Wait();
    mutex->Signal();
    return placeholder;
}

// I hate this
template class SafeBuffer<std::shared_ptr<Event>>;


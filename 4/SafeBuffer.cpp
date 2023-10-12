#include "SafeBuffer.h"
#include "Event.h"
#include <memory>

template <typename T>
SafeBuffer<T>::SafeBuffer(int size) {
    mutex = std::make_shared<Semaphore>(1);
    items = std::make_shared<Semaphore>(0);
    spaces = std::make_shared<Semaphore>(size);
}

template <typename T>
void SafeBuffer<T>::put(T element) {
    spaces->Wait();
    mutex->Wait();
    queue.push(element);
    mutex->Signal();
    items->Signal();
}

template <typename T>
T SafeBuffer<T>::get() {
    mutex->Wait();
    T element = queue.front();
    queue.pop();
    items->Wait();
    mutex->Signal();
    spaces->Signal();
    return element;
}

// I hate this
template class SafeBuffer<std::shared_ptr<Event>>;


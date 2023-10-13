#include "SafeBuffer.h"
#include "Event.h"
#include <memory>

/*!
    \class SafeBuffer
    \brief A threadsafe buffer implementation

    Uses two mutexes to prevent race conditions when adding or removing from the internal buffer.
*/

/*!
    \param size The internal buffer capacity
    \return SafeBuffer
*/
template <typename T>
SafeBuffer<T>::SafeBuffer(int size) {
    mutex = std::make_shared<Semaphore>(1);
    items = std::make_shared<Semaphore>(0);
    spaces = std::make_shared<Semaphore>(size);
}

/**
    \param element The element of type T to be inserted
    \return void
*/
template <typename T>
void SafeBuffer<T>::put(T element) {
    spaces->Wait();
    mutex->Wait();
    queue.push(element);
    mutex->Signal();
    items->Signal();
}

/*
    \return element of type T
*/
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

/// @cond DO_NOT_DOCUMENT

// I hate this
template class SafeBuffer<std::shared_ptr<Event>>;

/// @endcond
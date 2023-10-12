#ifndef SAFEBUFFER_H
#define SAFEBUFFER_H

#include "Semaphore.h"
#include <memory>
#include <queue>


template <typename T>
class SafeBuffer {
    private:
        std::shared_ptr<Semaphore> mutex;
        std::shared_ptr<Semaphore> items;
        std::queue<T> queue;
        T placeholder;

    public:
        SafeBuffer(int size);
        void put(T item);
        T get();
};

#endif




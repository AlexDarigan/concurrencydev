// Author: David Darigan


/// @cond DO_NOT_DOCUMENT

#include "Barrier.h"

Barrier::Barrier(){

  this->count = 0;
  threadNum = 0;
  condition = false;
  mutex = std::make_shared<Semaphore>(1);
  entry = std::make_shared<Semaphore>(0);
  exit = std::make_shared<Semaphore>(1);

}

Barrier::Barrier(int count){

  this->count = count;
  threadNum = 0;
  condition = false;
  mutex = std::make_shared<Semaphore>(1);
  entry = std::make_shared<Semaphore>(0);
  exit = std::make_shared<Semaphore>(1);
}
Barrier::~Barrier(){

}

int Barrier::getCount(){

  return this->count;
}

int Barrier::getMutexCount() {
  return mutex->getCount();
}

int Barrier::getEntryCount() {
  return entry->getCount();
}

int Barrier::getExitCount() {
  return exit->getCount();
}

void Barrier::waitForAll(){

  mutex->Wait();
  threadNum++;

  if(threadNum == count){
    exit->Wait();
    entry->Signal();
  }
  mutex->Signal();
  entry->Wait();
  entry->Signal();
  mutex->Wait();
  threadNum--;
  if(threadNum == 0) {
    entry->Wait();
    exit->Signal();
  }
  mutex->Signal();
  exit->Wait();
  exit->Signal();
}

/// @endcond
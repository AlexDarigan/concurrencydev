/// @cond DO_NOT_DOCUMENT

// Author: Joseph Kehoe
// Edited by: David Darigan (C00263218)
// Last Modified: Nov 23 2023

#include "Semaphore.h"
#include <iostream>
#include <stdio.h>

class Barrier
{
private:

  int count;
  int threadNum;
  bool condition;
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> entry;
  std::shared_ptr<Semaphore> exit;


public:

  Barrier();
  ~Barrier();
  Barrier(int count);
  int getCount();
  int getMutexCount();
  int getEntryCount();
  int getExitCount();
  void waitForAll();
};

/// @endcond
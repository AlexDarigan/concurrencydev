// Author: David Darigan

#include "Semaphore.h"
#include <iostream>
#include <stdio.h>

/*! \class Barrier
    \brief A Barrier Implementation

   Uses C++11 features such as mutex and condition variables to implement a Barrier class using Semaphores

*/
class Barrier
{
private:

  int count;
  int threadNum;
  bool condition;
  std::shared_ptr<Semaphore> mutex;
<<<<<<< Updated upstream
  std::shared_ptr<Semaphore> entry;
  std::shared_ptr<Semaphore> exit;

=======
  std::shared_ptr<Semaphore> barrier1;
  std::shared_ptr<Semaphore> entry;
  std::shared_ptr<Semaphore> exit;
>>>>>>> Stashed changes

public:

  Barrier();
  ~Barrier();
  Barrier(int count);
  void waitForAll();

/// @cond DO_NOT_DOCUMENT

  // These are only here as read only methods used in testing, so we're excluding them from documentation

  int getCount();
  int getMutexCount();
  int getEntryCount();
  int getExitCount();

/// @endcond
};

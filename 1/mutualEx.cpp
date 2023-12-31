// Author: Joseph Kehoe
// Edited by: David Darigan (C00263218)
// Last Modified: Nov 23 2023
// Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
// Git URL	: https://github.com/AlexDarigan/concurrencydev 
// Purpose: Test Driver for showcasing Threaded Code with Semaphores
/*! \file mutualEx.cpp
    \brief A Test Driver class for showcasing threaded code with Semaphores and Mututal Exclusion

*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>


static const int num_threads = 100;
int sharedVariable=0;


/*! \fn updateTask
    \brief An Implementation of Mutual Exclusion using Semaphores

   Uses C++11 features such as mutex and condition variables to implement an example of a rendezvous for threads

*/
/*! displays a message that is split in to 2 sections to show how a rendezvous works*/
void updateTask(std::shared_ptr<Semaphore> firstSem, int numUpdates){
 
  firstSem->Wait(); // The initial signal will be called
  for(int i=0;i<numUpdates;i++){
    sharedVariable++;
  }
  // After the first signal is called and we have processed the first thread,
  // we signal for the next thread to start
  firstSem->Signal();
}


int main(void){
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<Semaphore> aSemaphore(new Semaphore);
  std::shared_ptr<Semaphore> bSemaphore(new Semaphore);
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt) { 
    t=std::thread(updateTask,aSemaphore,1000);
    if(i == (num_threads - 1)) {
	// The last thread has been reached
	// This will signal one thread to start, which will then signal
	// the other threads in an almost recursive fashion
	aSemaphore->Signal();
    }
    i++;
  }	    
  std::cout << "Launched from the main\n";
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}

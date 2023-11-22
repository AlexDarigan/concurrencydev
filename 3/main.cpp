// Author	: David Darigan (C00263218)
// Licence	: GPL-3.0 (See LICENSE text for the full LICENSE)
// Git URL	: https://github.com/AlexDarigan/concurrencydev
/*! \file main.cpp
    \brief A Test Driver class for thread management through barriers (lab 3)

*/

#include "Barrier.h"
#include <thread>
#include <vector>

// Assertions used in testing
template <typename A, typename B>
void isEqual(A expected, B actual, std::string context) {
        bool result = (expected == actual);
        if(result) {
            std::cout << "SUCCESS on context: " + context << std::endl;
        } else {
            std::cout << "FAIL on context: " + context << " (" << "EXPECT: " << expected << ", " << "ACTUAL: " << actual << ")" << std::endl;
        }
}

/*! displays the first function in the barrier being executed */
void task(std::shared_ptr<Barrier> barrierObj){

  for(int i = 0; i < 5; ++i) {
    std::cout << "first " << std::endl;
    barrierObj->waitForAll();
    std::cout << "second" << std::endl;
    barrierObj->waitForAll();
  }
}

void testSemaphoreCounts() {
  std::vector<std::thread> threadArray(5);
  std::shared_ptr<Barrier> barrierObj( new Barrier(5));

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  isEqual(1, barrierObj->getMutexCount(), "Mutex returned to original count");
  isEqual(0, barrierObj->getEntryCount(), "Entry gate returned to original count");
  isEqual(1, barrierObj->getExitCount(), "Exit gate returned to original count");
}


int main(void){

  /*!< An array of threads*/
  std::vector<std::thread> threadArray(5);
  /*!< Pointer to barrier object*/
  std::shared_ptr<Barrier> barrierObj( new Barrier(5));

  for(int i=0; i < threadArray.size(); i++){
    threadArray[i]=std::thread(task,barrierObj);
  }

  for(int i = 0; i < threadArray.size(); i++){
    threadArray[i].join();
  }
  
  testSemaphoreCounts();
  return 0;
}

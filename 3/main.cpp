// Author: David Darigan

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
  
  return 0;
}

#include "Barrier.h"
#include "Event.h"
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>

static const int num_threads = 100;
const int size=20;
int sharedVariable = 0;

/*! \fn producer
    \brief Creates events and adds them to buffer
*/

// void producer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops){

//   for(int i=0;i<numLoops;++i){
//     //Produce event and add to buffer
//     std::shared_ptr<Event> e = std::make_shared<Event>(i);
//     theBuffer->put(e);
//   }
// }

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

// void consumer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops){

//   for(int i=0;i<numLoops;++i){
//     //Produce event and add to buffer
//     std::shared_ptr<Event> e = theBuffer->get();
//     e->consume();
//   }
// }

void updateTask(std::shared_ptr<Barrier> barrier, int count) {

}

int main(void){


  std::shared_ptr <Barrier> aBarrier = std::make_shared<Barrier>();
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> aBuffer(new SafeBuffer<std::shared_ptr<Event>>(size));

  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask,aBarrier,10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
  }
  std::cout << sharedVariable << std::endl;
  return 0;
}

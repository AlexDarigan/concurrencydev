#include "Barrier.h"
#include "Event.h"
#include "SafeBuffer.h"
#include <iostream>
#include <thread>
#include <vector>
#include "semaphore.h"

static const int num_threads = 10;
const int size=20;
int sharedVariable = 0;
Semaphore mutex;

void addValue(int v) {
  mutex.Wait();
  sharedVariable += v;
  mutex.Signal();
}

/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops){
  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    std::shared_ptr<Event> e = std::make_shared<Event>(i);
    theBuffer->put(e);
  }
}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> theBuffer, int numLoops){

  for(int i=0;i<numLoops;++i){
    //Produce event and add to buffer
    std::shared_ptr<Event> e = theBuffer->get();
    int num = e->consume();
    addValue(num);
  }
}

void updateTask(std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> buffer, int loops) {
  producer(buffer, loops);
  consumer(buffer, loops);
}

int main(void){

  mutex.Signal();
  std::shared_ptr <Barrier> aBarrier = std::make_shared<Barrier>();
  std::vector<std::thread> vt(num_threads);
  std::shared_ptr<SafeBuffer<std::shared_ptr<Event>>> aBuffer(new SafeBuffer<std::shared_ptr<Event>>(size));

  // Produce & consume data without deadlock or corrupting data

  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: vt){
    t=std::thread(updateTask, aBuffer, 10);
  }
  /**< Join the threads with the main thread */
  for (auto& v :vt){
      v.join();
   }
  std::cout << sharedVariable << std::endl;
  return 0;
}

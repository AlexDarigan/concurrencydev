/// @cond DO_NOT_DOCUMENT
// (We are copy-pasting this file so I've excluded this to prevent it appearing 8 times in doxygen)

#ifndef SEMAPHORE_H
#define SEMAPHORE_H 
#include <mutex>
#include <condition_variable>
#include <chrono>

class Semaphore
{
private:
    unsigned int m_uiCount;
    std::mutex m_mutex;
    std::condition_variable m_condition;

public:
    Semaphore(unsigned int uiCount=0)
          : m_uiCount(uiCount) { };
    void Wait();
    template< typename R,typename P >
    bool Wait(const std::chrono::duration<R,P>& crRelTime);
    void Signal();
    int getCount();

};

#endif

/// @endcond
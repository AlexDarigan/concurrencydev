/// @cond DO_NOT_DOCUMENT
// (We are copy-pasting this file so I've excluded this to prevent it appearing 8 times in doxygen)

#include <mutex>
#include <condition_variable>

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
    void Signal();
    int getCount();

};

/// @endcond
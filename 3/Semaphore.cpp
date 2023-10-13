/// @cond DO_NOT_DOCUMENT
// (We are copy-pasting this file so I've excluded this to prevent it appearing 8 times in doxygen)

#include "Semaphore.h"

void Semaphore::Wait()
{
      std::unique_lock< std::mutex > lock(m_mutex);
      m_condition.wait(lock,[&]()->bool{ return m_uiCount>0; });
      --m_uiCount; 
}

void Semaphore::Signal() 
{
      std::unique_lock< std::mutex > lock(m_mutex);
      ++m_uiCount;
      m_condition.notify_one();
}

int Semaphore::getCount() {
      return m_uiCount;
}

/// @endcond
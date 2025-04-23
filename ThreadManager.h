#ifndef THREADMANAGER_H
#define THREADMANAGER_H

#include <thread>
#include <vector>

class ThreadManager {
  public:
    ThreadManager();
    void startThreads();
    void joinThreads();
    int getThreadsNumber();

  private:
    int numThreads;
    std::vector<std::thread> threads;
    void threadFunction(int threadId);
};

#endif // THREADMANAGER_H

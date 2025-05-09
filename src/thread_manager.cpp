#include "thread_manager.hpp"
#include <iostream>
#include <taskflow/taskflow.hpp>

ThreadManager::ThreadManager()
    : numThreads(std::thread::hardware_concurrency()) {}

void ThreadManager::startThreads() {
    tf::Executor executor(numThreads);
    tf::Taskflow taskflow;

    for (int i = 0; i < numThreads; ++i) {
        taskflow.emplace([this, i]() { this->threadFunction(i); });
    }

    executor.run(taskflow).wait();
}

void ThreadManager::joinThreads() {
    for (auto &thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
}

int ThreadManager::getThreadsNumber() { return this->numThreads; }

void ThreadManager::threadFunction(int threadId) {
    std::cout << "Thread " << threadId << " is running.\n";
}

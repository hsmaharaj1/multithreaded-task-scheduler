#pragma once
#include <vector>
#include <thread>
#include "ThreadSafePriorityQueue.h"

using namespace std;

class ThreadPool {
public:
    ThreadPool(size_t numThreads);
    ~ThreadPool();
    void start();
    void stop();
    void addTask(const Task& task);

private:
    vector<thread> threads;
    ThreadSafePriorityQueue taskQueue;
    bool running;
    void workerFunction();
};
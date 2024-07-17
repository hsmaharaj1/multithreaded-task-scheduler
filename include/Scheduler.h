#pragma once
#include "ThreadPool.h"
using namespace std;

class Scheduler {
public:
    Scheduler(size_t numThreads);
    void addTask(int priority, function<void()> func);
    void start();
    void stop();

private:
    ThreadPool threadPool;
};
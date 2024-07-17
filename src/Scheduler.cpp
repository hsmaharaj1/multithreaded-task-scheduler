#include "Scheduler.h"
using namespace std;

Scheduler::Scheduler(size_t numThreads) : threadPool(numThreads) {}

void Scheduler::addTask(int priority, function<void()> func) {
    threadPool.addTask(Task(priority, move(func)));
}

void Scheduler::start() {
    threadPool.start();
}

void Scheduler::stop() {
    threadPool.stop();
}
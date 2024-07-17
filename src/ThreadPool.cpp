#include "ThreadPool.h"
#include <iostream>
using namespace std;

ThreadPool::ThreadPool(size_t numThreads) : running(false) {
    threads.reserve(numThreads);
}

ThreadPool::~ThreadPool() {
    if (running) {
        stop();
    }
}

void ThreadPool::start() {
    running = true;
    for (size_t i = 0; i < threads.capacity(); ++i) {
        threads.emplace_back(&ThreadPool::workerFunction, this);
    }
}

void ThreadPool::stop() {
    running = false;
    taskQueue.push(Task(0, [](){}));  // Push dummy task to wake up threads
    for (auto& thread : threads) {
        if (thread.joinable()) {
            thread.join();
        }
    }
    threads.clear();
}

void ThreadPool::addTask(const Task& task) {
    taskQueue.push(task);
}

void ThreadPool::workerFunction() {
    while (running) {
        try {
            Task task = taskQueue.pop();
            if (running) {  // Check again to handle the case of dummy task
                task.execute();
            }
        } catch (const exception& e) {
            cerr << "Exception in task execution: " << e.what() << endl;
        }
    }
}
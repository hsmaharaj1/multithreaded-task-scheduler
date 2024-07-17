#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Task.h"
using namespace std;

class ThreadSafePriorityQueue {
public:
    void push(const Task& task) {
        lock_guard<std::mutex> lock(mutex);
        queue.push(task);
        cv.notify_one();
    }

    Task pop() {
        unique_lock<std::mutex> lock(mutex);
        cv.wait(lock, [this] { return !queue.empty(); });
        Task task = queue.top();
        queue.pop();
        return task;
    }

    bool empty() const {
        lock_guard<std::mutex> lock(mutex);
        return queue.empty();
    }

private:
    // Create a min-heap (lowest priority first)
    priority_queue<Task, vector<Task>, greater<Task>> queue;
    mutable std::mutex mutex;
    condition_variable cv;
};
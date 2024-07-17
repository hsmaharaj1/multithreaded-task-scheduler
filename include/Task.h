#pragma once
#include <functional>
using namespace std;

class Task {
public:
    Task(int priority, function<void()> func);
    void execute();
    int getPriority() const;

    // Add these lines to declare both operators
    bool operator<(const Task& other) const;
    bool operator>(const Task& other) const;

private:
    int priority;
    function<void()> func;
};
#include "Task.h"
using namespace std;

Task::Task(int priority, function<void()> func)
    : priority(priority), func(move(func)) {}

void Task::execute() {
    func();
}

int Task::getPriority() const {
    return priority;
}

bool Task::operator<(const Task& other) const {
    return priority < other.priority;
}

bool Task::operator>(const Task& other) const {
    return priority > other.priority;
}
/*
#include <iostream>
#include <chrono>
#include <thread>
#include "Scheduler.h"

int main() {
    Scheduler scheduler(2);  // Create a scheduler with 4 threads

    scheduler.addTask(1, []() {
        std::cout << "Task 1 executing\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));
    });

    scheduler.addTask(2, []() {
        std::cout << "Task 2 executing\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    });
    scheduler.addTask(4, []() {
        std::cout << "Task 3 executing\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    });
    scheduler.addTask(1, []() {
        std::cout << "Task 4 executing\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    });

    scheduler.start();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    scheduler.stop();

    return 0;
}

*/


#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "Scheduler.h"

using namespace std;

// Added work simulators with random durations
void simulateWork(int taskId, int duration) {
    cout << "Task " << taskId << " started\n";
    this_thread::sleep_for(chrono::milliseconds(duration));
    cout << "Task " << taskId << " completed in " << duration << endl;
}

int main() {
    Scheduler scheduler(2);  // Create a scheduler with 4 threads

    // Random number generator for task durations
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1000, 5000);

    // Add tasks with various priorities
    scheduler.addTask(3, [&]() { simulateWork(1, dis(gen)); });
    scheduler.addTask(1, [&]() { simulateWork(2, dis(gen)); });
    scheduler.addTask(5, [&]() { simulateWork(3, dis(gen)); });
    scheduler.addTask(2, [&]() { simulateWork(4, dis(gen)); });
    scheduler.addTask(4, [&]() { simulateWork(5, dis(gen)); });
    scheduler.addTask(3, [&]() { simulateWork(6, dis(gen)); });
    scheduler.addTask(1, [&]() { simulateWork(7, dis(gen)); });
    scheduler.addTask(5, [&]() { simulateWork(8, dis(gen)); });

    scheduler.start();

    // Wait for all tasks to complete
    this_thread::sleep_for(chrono::seconds(10));

    scheduler.stop();

    return 0;
}
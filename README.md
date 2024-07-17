# Multithreaded Task Scheduler

## Overview

This project is a multithreaded task scheduler implemented in C++. The task scheduler efficiently manages and executes multiple tasks concurrently using a thread pool. The scheduler allows for tasks to be added with varying priorities, ensuring that higher-priority tasks are executed first.

## Project Description

The multithreaded task scheduler is designed to manage and execute tasks using a fixed number of threads. Each task can be assigned a priority, and the scheduler will ensure that tasks with higher priorities are executed before those with lower priorities. This is particularly useful in environments where tasks have varying levels of importance and need to be managed efficiently.

### Key Features

- **Thread Pool**: The scheduler uses a pool of worker threads to execute tasks concurrently.
- **Priority Scheduling**: Tasks can be added with different priorities, and the scheduler will manage the execution order based on these priorities.
- **Task Simulation**: The included example simulates tasks with random durations to demonstrate the scheduler's functionality.

## Folder Structure

- `bin/` - Directory for the compiled binary executable (will get built).
- `include/` - Directory for header files.
- `obj/` - Directory for object files (will get built).
- `src/` - Directory for source files.
- `Makefile` - File for building the project.

## Makefile

The provided Makefile automates the build process. Below are the key variables and rules used:

### Variables

- `CXX` - The C++ compiler to use (`g++`).
- `CXXFLAGS` - Compiler flags (`-std=c++17 -Wall -I./include`).
- `SRCDIR` - Source directory (`src`).
- `OBJDIR` - Object directory (`obj`).
- `BINDIR` - Binary directory (`bin`).
- `SOURCES` - All source files in the `src` directory.
- `OBJECTS` - Corresponding object files in the `obj` directory.
- `EXECUTABLE` - The final executable (`bin/TaskScheduler.exe`).

### Targets

- `all` - Default target to build the executable.
- `$(EXECUTABLE)` - Links object files to create the final executable.
- `$(OBJDIR)/%.o` - Compiles source files into object files.
- `$(OBJDIR)` - Creates the `obj` directory if it doesn't exist.
- `$(BINDIR)` - Creates the `bin` directory if it doesn't exist.
- `clean` - Removes the `obj` and `bin` directories.

## Build Instructions

1. Ensure you have `g++` installed on your system.
2. Navigate to the project directory.
3. Run `make` to compile the project.
4. The executable will be created in the `bin` directory as `TaskScheduler.exe`.

## Cleaning Up

To remove the compiled files and directories, run:
```sh
make clean

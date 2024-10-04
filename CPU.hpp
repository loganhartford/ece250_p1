#ifndef CPU_HPP
#define CPU_HPP

#include <iostream>
#include <string>
using namespace std;

#include "Deque.hpp"

class CPU
{
public:
    CPU(int numCores);
    ~CPU();

    int getNumCores();
    int getSize(int core);
    int getCapacity(int core);

    int addTask(int task);
    int runTask(int core);
    string sleep(int core);

private:
    int numCores;
    Deque *cores;

    int stealTask();
};

#endif
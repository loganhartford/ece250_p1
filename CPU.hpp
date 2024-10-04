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

    string getSize(int core);
    string getCapacity(int core);

    string addTask(int task);
    string runTask(int core);

    string sleep(int core);
    string shutdown();

private:
    int numCores;
    Deque *cores;

    bool validateCore(int core);

    int stealTask();
};

#endif
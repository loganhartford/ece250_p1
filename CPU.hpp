#ifndef CPU_HPP
#define CPU_HPP

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
    void sleep(int core);

private:
    int numCores;
    Deque *cores;

    int stealTask();
};

#endif
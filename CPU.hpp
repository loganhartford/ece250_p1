#ifndef CPU_HPP
#define CPU_HPP

#include "Deque.hpp"

class CPU
{
public:
    CPU(int numCores);
    ~CPU();

    int addTask(int task);

private:
    int numCores;
    Deque *cores;
};

#endif
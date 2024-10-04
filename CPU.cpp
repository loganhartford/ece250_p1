#include "CPU.hpp"

CPU::CPU(int numCores)
{
    this->numCores = numCores;
    this->cores = new Deque[numCores];
}

CPU::~CPU()
{
    delete[] cores;
}

int CPU::addTask(int task)
{
    int minSize = cores[0].getSize();
    int minIndex = 0;
    for (int i = 1; i < numCores; i++)
    {
        if (cores[i].getSize() < minSize)
        {
            minSize = cores[i].getSize();
            minIndex = i;
        }
    }
    cores[minIndex].pushFront(task);

    return minIndex;
}
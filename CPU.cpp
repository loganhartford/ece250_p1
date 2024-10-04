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

int CPU::getNumCores()
{
    return numCores;
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

int CPU::stealTask()
{
    int maxSize = cores[0].getSize();
    int maxIndex = 0;
    for (int i = 1; i < numCores; i++)
    {
        if (cores[i].getSize() > maxSize)
        {
            maxSize = cores[i].getSize();
            maxIndex = i;
        }
    }
    return cores[maxIndex].popBack();
}

int CPU::runTask(int core)
{
    if (cores[core].getSize() == 0)
    {
        int task = stealTask();
        if (task != -1)
        {
            cores[core].pushFront(task);
        }
        return -1;
    }
    return cores[core].popBack();
}
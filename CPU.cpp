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

int CPU::getSize(int core)
{
    return cores[core].getSize();
}

int CPU::getCapacity(int core)
{
    return cores[core].getCapacity();
}

int CPU::addTask(int task)
{
    // TODO: handle case where all cores are full
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
    // TODO: handle case where all cores are empty
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

string CPU::sleep(int core)
{
    if (cores[core].getSize() == 0)
    {
        return "core " + to_string(core) + " has no tasks to assign";
    }

    string result = "";

    while (cores[core].getSize() > 0)
    {
        int task = cores[core].popFront();

        int minSize = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < numCores; i++)
        {
            if (i != core && cores[i].getSize() < minSize)
            {
                minSize = cores[i].getSize();
                minIndex = i;
            }
        }

        if (minIndex != -1)
        {
            cores[minIndex].pushFront(task);
            result += "task " + to_string(task) + " assigned to core " + to_string(minIndex) + " ";
        }
    }

    return result;
}

string CPU::shudown()
{
    string result = "";

    for (int i = 0; i < numCores; i++)
    {
        while (cores[i].getSize() > 0)
        {
            result += "deleting task " + to_string(cores[i].popBack()) + " from core " + to_string(i) + " ";
        }
    }

    if (result == "")
    {
        return "no tasks to remove";
    }
    return result;
}
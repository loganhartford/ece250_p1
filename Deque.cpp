#include "Deque.hpp"

Deque::Deque()
{
    queue = new int[4];
    size = 0;
    capacity = 4;
}

Deque::~Deque()
{
    delete[] queue;
}

void Deque::pushFront(int value)
{
    for (int i = size; i > 0; i--)
    {
        queue[i] = queue[i - 1];
    }
    queue[0] = value;
    size++;

    if (size == capacity)
    {
        int *newQueue = new int[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            newQueue[i] = queue[i];
        }
        delete[] queue;
        queue = newQueue;
        capacity *= 2;
    }
}

void Deque::pushBack(int value)
{
    if (size == capacity)
    {
        int *newQueue = new int[capacity * 2];
        for (int i = 0; i < size; i++)
        {
            newQueue[i] = queue[i];
        }
        delete[] queue;
        queue = newQueue;
        capacity *= 2;
    }
    queue[size] = value;
    size++;
}

int Deque::popBack()
{
    if (size == 0)
    {
        return -1;
    }
    size--;
    return queue[size];
}

int Deque::popFront()
{
    if (size == 0)
    {
        return -1;
    }
    int value = queue[0];
    for (int i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
    }
    size--;
    return value;
}

int Deque::getSize()
{
    return size;
}

int Deque::getCapacity()
{
    return capacity;
}

/* Just for debugging */
void Deque::print()
{
    for (int i = 0; i < size; i++)
    {
        cout << queue[i] << " ";
    }
    cout << endl;
}
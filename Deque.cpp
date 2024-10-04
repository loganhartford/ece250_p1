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

void Deque::resize(int newCapacity)
{
    int *newQueue = new int[newCapacity];
    for (int i = 0; i < size; i++)
    {
        newQueue[i] = queue[i];
    }

    delete[] queue;
    queue = newQueue;
    capacity = newCapacity;
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
        resize(capacity * 2);
    }
}

void Deque::pushBack(int value)
{
    queue[size] = value;
    size++;

    if (size == capacity)
    {
        resize(capacity * 2);
    }
}

int Deque::popBack()
{
    if (size == 0)
    {
        return -1;
    }
    size--;
    int task = queue[size];
    if (size > 0 && size <= capacity / 4 && capacity > 2)
    {
        resize(capacity / 2);
    }
    return task;
}

int Deque::popFront()
{
    if (size == 0)
    {
        return -1;
    }
    int task = queue[0];
    for (int i = 0; i < size - 1; i++)
    {
        queue[i] = queue[i + 1];
    }
    size--;

    if (size > 0 && size <= capacity / 4 && capacity > 2)
    {
        resize(capacity / 2);
    }
    return task;
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
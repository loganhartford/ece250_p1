#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <iostream>
#include <string>
using namespace std;

class Deque
{
public:
    Deque();
    ~Deque();

    void pushBack(int value);
    void pushFront(int value);
    int popBack();
    int popFront();
    int getSize();
    int getCapacity();
    void print();

private:
    int *queue;
    int size;
    int capacity;
};

#endif
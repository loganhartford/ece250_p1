#include <iostream>
#include <string>
using namespace std;

#include "CPU.hpp"

int main()
{
    string cmd;
    CPU *cpu = nullptr;
    int core;

    while (cin >> cmd)
    {
        core = -1;
        if (cmd == "ON")
        {
            int cores;
            cin >> cores;
            if (cpu)
            {
                cout << "failure" << endl;
            }
            else
            {
                cpu = new CPU(cores);
                cout << "success" << endl;
            }
        }
        else if (cmd == "SPAWN")
        {
            int task;
            cin >> task;
            if (cpu)
            {
                cout << cpu->addTask(task) << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "RUN")
        {
            cin >> core;
            if (cpu)
            {
                cout << cpu->runTask(core) << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "SLEEP")
        {
            cin >> core;
            if (cpu)
            {
                cout << cpu->sleep(core) << endl;
            }
        }
        else if (cmd == "SHUTDOWN")
        {
            if (cpu)
            {
                cout << cpu->shutdown() << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "SIZE")
        {
            cin >> core;
            if (cpu)
            {
                cout << cpu->getSize(core) << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "CAPACITY")
        {
            cin >> core;
            if (cpu)
            {
                cout << cpu->getCapacity(core) << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "END")
        {
            if (cpu)
            {
                delete cpu;
                cpu = nullptr;
            }
            return 0;
        }
    }

    if (cpu)
    {
        delete cpu;
        cpu = nullptr;
    }
    return 0;
}

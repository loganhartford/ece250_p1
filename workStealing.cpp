#include <iostream>
#include <string>
using namespace std;

#include "CPU.hpp"

int main()
{
    string cmd;
    CPU *cpu = nullptr;

    while (cin >> cmd)
    {
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
            if (cpu && task > 0)
            {
                int core = cpu->addTask(task);
                cout << "core " << core << " assigned task " << task << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "RUN")
        {
            int core;
            cin >> core;
            if (cpu && core >= 0 && core < cpu->getNumCores())
            {
                string result = cpu->runTask(core);
                cout << result << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "SLEEP")
        {
            int core;
            cin >> core;
            if (cpu && core >= 0 && core < cpu->getNumCores())
            {
                string result = cpu->sleep(core);
                cout << result << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "SHUTDOWN")
        {
            if (cpu)
            {
                string result = cpu->shudown();
                cout << result << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "SIZE")
        {
            int core;
            cin >> core;
            if (cpu && core >= 0 && core < cpu->getNumCores())
            {
                cout << "size is " << cpu->getSize(core) << endl;
            }
            else
            {
                cout << "failure" << endl;
            }
        }
        else if (cmd == "CAPACITY")
        {
            int core;
            cin >> core;
            if (cpu && core >= 0 && core < cpu->getNumCores())
            {
                cout << "capacity is " << cpu->getCapacity(core) << endl;
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
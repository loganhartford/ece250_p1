#include <iostream>
#include <string>
using namespace std;

int main()
{
    string cmd;

    while (cin >> cmd)
    {
        if (cmd == "ON")
        {
            cout << "success" << endl;
        }
        else if (cmd == "SPAWN")
        {
            cout << "failure" << endl;
        }
        else if (cmd == "RUN")
        {
            cout << "failure" << endl;
        }
        else if (cmd == "SLEEP")
        {
            cout << "failure" << endl;
        }
        else if (cmd == "SHUTDOWN")
        {
            cout << "failure" << endl;
        }
        else if (cmd == "SIZE")
        {
            cout << "failure" << endl;
        }
        else if (cmd == "CAPACITY")
        {
            cout << "failure" << endl;
        }
        else if (cmd == "END")
        {
            return 0;
        }

        return 0;
    }
}
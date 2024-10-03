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

        return 0;
    }
}
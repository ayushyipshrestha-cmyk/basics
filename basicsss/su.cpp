#include <iostream>
using namespace std;
int main()
{
    int code;
    cout << "Enter the code:";
    cin >> code;
    if (code == 7 && code == 3)
    {
        cout << "Error in code" << endl;
        return 0;
    }
    string dir[] = {"left", "right", "up", "down"};
    for (int i = 0; i < 4; i++)
        if (code & (1 << i))
        {
            cout << "POINT IS " << dir[i] << endl;
        }

    return 0;
}
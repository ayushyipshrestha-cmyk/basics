#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter and integer";
    cin >> n;
    cout << "Binary: ";
    bool start = false;
    for (int i = 31; i >= 0; i--)
    {
        int bit = (n >> i) & 1;
        if (bit == 1)
            start = true;
        if (start || i == 0)
            cout << bit;
    }

    cout << endl;
    return 0;
}

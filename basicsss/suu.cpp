#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    int code = ((y > 500) << 3) | ((y < 100) << 2) | ((x > 400) << 1) | (x < 100);

    cout << "Code: " << code << endl;
}
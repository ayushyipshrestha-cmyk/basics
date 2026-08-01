#include <iostream>
using namespace std;
int main()
{
    int a, n;
    cout << "Enter a number :\n";
    cin >> n;
    for (int i = 1; i <= 10; i++)
    {
        a = n * i;

        cout << n << "x" << i << "=" << a << endl;
    }
    cout << "The multiplication table\n"
         << endl;
    return 0;
}
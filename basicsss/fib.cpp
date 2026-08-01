#include <iostream>
using namespace std;
int fib(int n)
{
    if (n < 2)
    {
        return 1;
    }

    return fib(n - 2) + fib(n - 1);
}
int main()
{
    int a;
    cout << "Enter an Idex Number:\n";
    cin >> a;

    cout << "the fibonaci number is " << fib(a) << endl; // fuction overloading hunhca
    return 0;
}
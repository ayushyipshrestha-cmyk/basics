#include <iostream>
using namespace std;

int main()
{
    int num, divisor, power = 0;
    cout << "Enter number and divisor (must be power of 2): ";
    cin >> num >> divisor;

    int temp = divisor;
    while (temp > 1)
    {
        temp >>= 1;
        power++;
    }

    int result = num >> power;
    cout << "Result of " << num << " / " << divisor << " = " << result << endl;
    return 0;
}
#include <iostream>
using namespace std;

// 1. Return type changed from 'int' to 'double'
double harmonic(int n)
{
    double sum = 0.0;
    for (int i = 1; i <= n; i++)
    {
        // 2. Used 1.0 instead of 1 to prevent integer division
        sum += 1.0 / i;
    }
    return sum;
}

int main()
{
    int n;
    cout << "Enter the number n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Please enter a positive integer greater than 0." << endl;
        return 1;
    }

    // 3. Store and display the returned double value

    cout << "The harmonic series sum is: " << harmonic(n) << endl;

    return 0;
}
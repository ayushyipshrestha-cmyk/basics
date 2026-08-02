#include <iostream>
using namespace std;
int square(int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += n * i * i;
    }
    return sum;
}
int main()
{
    int n;
    cout << "ENTER THE REQUIRED NUMERS: \n";
    cin >> n;
    cout << "THE SUM OF GIVEN NUMBER IS :" << square(n) << endl;
    return 0;
}

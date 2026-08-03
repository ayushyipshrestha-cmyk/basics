#include <iostream>
using namespace std;
int sume(int a)
{
    int sum = 0;
    if (a <= 0)
    {
        return 1;
    }
    for (int i = 0; i < a; i++)
    {
        sum += a;
    }
    return sum;
}
int main()
{

    cout << "The Total sum of the one number given is " << sume(0) << endl;
    return 0;
}
#include <iostream>
using namespace std;
void swappoint(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = *a;
}
int &swapReferenceVar(int &a, int &b)
{
    int temp = a;
    a = b;
    b = a;
    return a;
}
int main()
{
    int x = 1000, y = 100000;
    cout << "The value of X is\n " << x << "\nThe value of Y is" << y << endl;
    swapReferenceVar(x, y) = 71234;
    cout << "The value of X is \n"
         << x << "\nThe value of Y is" << y << endl;
    return 0;
}
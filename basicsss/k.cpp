#include <iostream>
using namespace std;
void swapPoint(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{

    int x = 100;
    int y = 200;
    cout << "THE VALUE OF X IS " << x << "THE VALUE OF Y IS " << y << endl;
    swapPoint(&x, &y); // callig the fuction
    cout << "THE VALUE OF X IS " << x << "THE VALUE OF Y IS " << y << endl;
    return 0;
}
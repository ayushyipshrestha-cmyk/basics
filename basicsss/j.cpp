#include <iostream>
using namespace std;
float moneysalary(int current, float factor = 1.01)
{
    return current * factor;
}
int main()
{

    int money = 10000;
    cout << "If you have " << money << "you will recieve" << moneysalary(money) << "after 1 year " << endl;
    cout << "IF YOU ARE VIP THE SALARY" << money << "you will recieve" << moneysalary(money, 1.14) << "after 1 year completion" << endl;
    return 0;
}

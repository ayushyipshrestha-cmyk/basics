#include <iostream>
using namespace std;
typedef struct sujata
{
    int eid;
    char favchar;
    float salary;
} ep;

int main()
{
    ep ayush;
    ayush.eid = 1;
    ayush.favchar = 'c';
    ayush.salary = 130000;
    cout << "THE ID OF SUJATA:\n"
         << ayush.eid << endl;
    cout << "THE FAVCHAR OF SUJATA:\n"
         << ayush.favchar << endl;

    cout << "THE SALARY OF SUJATA :\n"
         << ayush.salary << endl;
    return 0;
}
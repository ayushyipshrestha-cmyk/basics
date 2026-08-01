#include <iostream>
using namespace std;
struct sujata
{
    int eid;
    char favchar;
    float rice;
};
typedef union suje
{
    int id;
    char car;
    float rice;

} ep;

int main()
{

    ep ayush;
    ayush.id = 1;
    ayush.car = 'c';
    ayush.rice = 130000;
    cout << "THE ID OF SUJATA:\n"
         << ayush.id << endl;
    cout << "THE FAVCHAR OF SUJATA:\n"
         << ayush.car << endl;

    cout << "THE rice OF SUJATA :\n"
         << ayush.rice << endl;
    return 0;
}
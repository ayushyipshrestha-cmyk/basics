#include <iostream>
using namespace std;
typedef struct sujata
{
    int a;
    char su;
    float p;

} ep;
int main()
{
    ep suj;
    suj.a = 1;
    suj.su = 'c';
    suj.p = 3.44;
    cout << "THE EMPLOYS HAS" << suj.a << endl;
    return 0;
}
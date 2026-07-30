#include <iostream>
using namespace std;
inline float circlearea(float radius)
{
    return 3.14 * radius * radius;
}
int main()
{
    float r;
    cout << "enter the radius:";
    cin >> r;
    cout << "the area of the circle is " << circlearea(r) << endl;
    return 0;
}

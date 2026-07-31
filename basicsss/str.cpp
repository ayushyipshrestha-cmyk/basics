#include <iostream>
using namespace std;
void reversestring(string &str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
    {
        swap(str[i], str[n - i - 1]);
    }
}
int main()
{
    string str;
    cout << "<ENTER THE STRING:";
    cin >> str;
    cout << "The Orginal String value" << str << endl;
    reversestring(str);
    cout << "The reversed string value is :" << str << endl;
    return 0;
}
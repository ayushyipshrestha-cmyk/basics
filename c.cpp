#include <iostream>
using namespace std;
int sujata(const int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cout << "Enter the required number:\n";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter the " << n << "Numbers:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // index is shown the place value
    }
    // calling the fuction sujata;
    cout << "THE REUQIRED SUM IS :\n"
         << sujata(arr, n) << endl;
    delete[] arr;
    arr = nullptr;
    return 0;
}
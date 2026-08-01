#include <iostream>
using namespace std;
void sorting(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        { // it indicates the index real time value
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " \t";
    }
    cout << endl;
}
// n-1 says the numb,er of passes which   an  cardinal number of array contains

int main()
{
    int n = 5;
    int arr[] = {32, 2, 874, 51, 41};

    sorting(arr, n);
    printarray(arr, n);

    return 0;
}
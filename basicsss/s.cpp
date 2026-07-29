#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, index;
    cout << "Enter any size for array:";
    cin >> n;
    int *arr = new int[n];
    cout << "enter" << "n" << "element";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[n];
    }
    cout << "Enter an index for pivot";
    cin >> index;

    int pivot = arr[index];
    vector<int> smaller;
    vector<int> larger;

    for (int i = 0; i < n; i++)
    {
        if (i == index)
            continue;
        if (arr[i] < pivot)
        {
            smaller.push_back(arr[i]);
        }
        else
        {
            if (arr[i] > pivot)
            {
                larger.push_back(arr[i]);
            }
        }
    }
    int k = 0;
    for (int val : smaller)
    {
        arr[k++] = val;
    }
    arr[k++] = pivot;
    for (int val : larger)
    {
        arr[k++] = val;
    }
    cout << "Repositioned arry";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "";
    }
    cout << endl;
    delete[] arr;
    return 0;
}
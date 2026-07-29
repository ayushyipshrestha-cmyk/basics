#include <iostream>
using namespace std;

int main()
{
    int n, idx;
    cout << "Enter size: ";
    cin >> n;

    int *arr = new int[n];
    int *result = new int[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter index i: ";
    cin >> idx;

    int pivot = arr[idx];
    int left = 0, right = n - 1;

    // Fill smaller items from the left, larger items from the right
    for (int i = 0; i < n; i++)
    {
        if (i == idx)
            continue; // Skip pivot for now
        if (arr[i] < pivot)
            result[left++] = arr[i];
        else
            result[right--] = arr[i];
    }

    // Left now points to the exact empty spot in the middle!
    result[left] = pivot;

    // Print result
    cout << "Repositioned array: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";

    delete[] arr;
    delete[] result;
    return 0;
}

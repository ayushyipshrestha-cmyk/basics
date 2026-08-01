#include <iostream>
using namespace std;

// One template function replaces all three overloaded functions:
template <class T>
void sort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

int main()
{
    int Arr[] = {3, 1, 2};
    char cArr[] = {'z', 'a', 'c'};
    float fArr[] = {3.3f, 1.1f, 2.2f};

    sort(Arr, 3);  // Automatically generates sort<int>
    sort(cArr, 3); // Automatically generates sort<char>
    sort(fArr, 3); // Automatically generates sort<float>

    cout << "Sorted Ints: " << Arr[0] << " " << Arr[1] << " " << Arr[2] << endl;
    return 0;
}
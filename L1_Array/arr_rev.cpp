//reversing the elements of an array
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[n - 1 - i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << temp[i] << " ";
    }

    return 0;
}
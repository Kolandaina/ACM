#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            for (int j = a[i - 1]; j < a[i]; j++)
            {
                cout << j << " ";
            }
        }
        else
        {
            for (int j = a[i - 1]; j > a[i]; j--)
            {
                cout << j << " ";
            }
        }
    }
    cout << a[n - 1] << endl;
    return 0;
}
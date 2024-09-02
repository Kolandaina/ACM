#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int a[100];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        int sum = 0;
        for (int i = 0; i < n / 2; i++)
        {
            sum += a[n - i - 1] - a[i];
        }
        cout << sum << endl;
    }
    return 0;
}
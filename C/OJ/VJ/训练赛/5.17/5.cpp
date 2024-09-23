#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], max_n, idx = 1;
map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] > max_n)
        {
            max_n = mp[a[i]];
            idx = i;
        }
    }
    cout << n - max_n << endl;
    for (int i = idx + 1; i <= n; i++)
    {
        if (a[i] != a[idx])
        {
            if (a[i] > a[idx])
                cout << "2 ";
            else
                cout << "1 ";
            cout << i << " " << i - 1 << endl;
        }
    }
    for (int i = idx - 1; i >= 1; i--)
    {
        if (a[i] != a[idx])
        {
            if (a[i] > a[idx])
                cout << "2 ";
            else
                cout << "1 ";
            cout << i << " " << i + 1 << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int a[100000], b[100000];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b, b + n);
        int m = unique(b, b + n) - b;
        map<int, int> mp;
        for (int i = 0; i < m; i++)
        {
            mp[b[i]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            a[i] = mp[a[i]];
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
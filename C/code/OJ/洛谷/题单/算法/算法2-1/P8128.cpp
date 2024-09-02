#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n, m;
int a[N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    cin >> m;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[l - 1] << endl;
    }
    return 0;
}
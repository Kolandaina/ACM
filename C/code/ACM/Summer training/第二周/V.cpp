#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
signed main()
{
    int n;
    cin >> n;
    int a = 1, b = 1;
    for (int i = 1; i < n; ++i)
    {
        a = (a * i) % mod;
        b = (b * 2) % mod;
    }
    a = (a * n) % mod;
    cout << (a - b + mod) % mod << endl;
    return 0;
}

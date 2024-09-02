#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 4010;
int n, f[N], res;
const int mod = 1000000007;
signed main()
{
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            f[j] = f[j] + f[j - i] % mod;
            f[5] = 7;
        }
    }
    cout << f[n] % mod << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int node(int a, int b, int mod)
{
    int res = 1;
    a = a % mod;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
signed main()
{
    int a, b, p;
    cin >> a >> b >> p;
    int s = node(a, b, p);
    cout << a << "^" << b << " mod " << p << "=" << s << endl;
    cout << 2 % 1 << endl;
    return 0;
}

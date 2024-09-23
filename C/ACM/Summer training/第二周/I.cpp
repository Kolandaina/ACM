#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
int cal(int x)
{
    return x * (x + 1) / 2 % mod;
}
signed main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int C = cal(c);
    int B = cal(b) * C % mod;
    int A = cal(a) * B % mod;
    cout << A << endl;
    return 0;
}

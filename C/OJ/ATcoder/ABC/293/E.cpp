#include <bits/stdc++.h>
#define int long long
using namespace std;
int Mod;
inline int ksm(int x, int k)
{
    int ans = 1;
    while (k)
    {
        if (k & 1)
            ans *= x, ans %= Mod;
        x *= x;
        x %= Mod;
        k >>= 1;
    }
    return ans;
}
inline int calc(int x, int k)
{
    if (k == 1) return 1;
    int tc = ksm(x, k / 2);
    if (k & 1)
        return (calc(x, k / 2) * (tc + 1) % Mod + ksm(x, k - 1)) % Mod;
    return (calc(x, k / 2) * (tc + 1) % Mod);
}
signed main()
{
    int a, x;
    cin >> a >> x >> Mod;
    cout << calc(a, x) % Mod << endl;
    return 0;
}

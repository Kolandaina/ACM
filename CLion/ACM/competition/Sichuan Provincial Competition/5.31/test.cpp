#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;
#define For(i, a, b) for(int (i)=(a);(i) < (b); ++(i))
#define x     first
#define iOS  ios_base::sync_with_stdio
#define double long double
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> os;
const int maxn = 1e5 + 100, mod = 1e9 + 7;
#define  int long long
int p[maxn], x[maxn], f[maxn], a, b, n, q;

signed main()
{
    iOS(false);
    cin >> n >> q;
    For(i, 0, 2)cin >> f[i];
    cin >> a >> b;
    For(i, 2, maxn)f[i] = (1LL * a * f[i - 2] + 1LL * b * f[i - 1]) % mod;
    For(i, 0, n)cin >> x[i];
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        if (l < r)
        {
            p[l] = (p[l] + f[0]) % mod;
            p[l + 1] = (p[l + 1] + f[1]) % mod;
            p[l + 1] = (1LL * p[l + 1] + mod - 1LL * ((1LL * b * f[0]) % mod)) % mod;
            p[r + 1] = (1LL * p[r + 1] + mod - f[r - l + 1]) % mod;
            p[r + 2] = (1LL * p[r + 2] + mod - 1LL * ((1LL * a * f[r - l]) % mod)) % mod;
        } else
        {
            p[l] = (p[l] + f[0]) % mod;
            p[r + 1] = (1LL * p[r + 1] + mod - ((1LL * b * f[0]) % mod)) % mod;
            p[r + 2] = (1LL * p[r + 2] + mod - 1LL * ((1LL * a * f[0]) % mod)) % mod;
        }
    }
    For(i, 0, n)
    {
        if (i > 1)
            p[i] = (1LL * p[i] + a * p[i - 2]) % mod;
        if (i)
            p[i] = (1LL * p[i] + b * p[i - 1]) % mod;
        x[i] = (p[i] + x[i]) % mod;
        cout << x[i];
        if (i + 1 < n)
            cout << ' ';
    }
    cout <<
         endl;
}


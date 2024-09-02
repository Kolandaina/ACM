#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int mod = 1e9 + 7;
int pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
inline void slove()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int x : v)
    {
        mp[x]++;
    }
    n = unique(v.begin(), v.end()) - v.begin();
    v.reserve(n);
    int res = 1, ans = 0;
    for (int i = 0, j = 0; i < n;)
    {
        while (j < n && v[j] < v[i] + m)
        {
            res = res * (mp[v[j++]]) % mod;
        }
        if (j - i == m)
        {
            ans += res;
        }
        res = res * pow(mp[v[i++]], mod - 2) % mod;
    }
    cout << ans % mod << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}
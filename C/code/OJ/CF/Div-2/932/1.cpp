#include <bits/stdc++.h>
#define int long long
#define ldb long double
#define For(i, a, b) for (i = a; i <= b; i++)
#define FOR(i, a, b) for (i = a; i >= b; i--)
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
char b[N];
void solve() { int i; }
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int i, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        For(i, 1, n) cin >> a[i];
        For(i, 1, n) cin >> b[i];
        int l = 1, r = n, res = 1;
        For(i, 1, n)
        {
            if (b[i] == 'L')
                l++;
            else
                r--;
        }
        std::vector<int> ans;
        FOR(i, n, 1)
        {
            if (b[i] == 'L')
            {
                l--;
                res = res * a[l] % m;
            }
            else
            {
                r++;
                res = res * a[r] % m;
            }
            ans.push_back(res);
        }
        reverse(ans.begin(), ans.end());
        for (auto u : ans) cout << u << ' ';
        cout << '\n';
        solve();
    }
    return 0;
}
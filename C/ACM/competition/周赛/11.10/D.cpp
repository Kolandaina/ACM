#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int ss[6][N];
string temp[6] = {"abc", "acb", "bac", "bca", "cab", "cba"};
inline void slove()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ss[i][j] = ss[i][j - 1] + (s[j - 1] != temp[i][(j - 1) % 3]);
        }
    }

    while (m--)
    {
        int l, r, ans = N;
        cin >> l >> r;
        for (int t = 0; t < 6; t++)
            ans = min(ans, ss[t][r] - ss[t][l - 1]);
        cout << ans << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}
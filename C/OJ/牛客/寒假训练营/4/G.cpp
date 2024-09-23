#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n, m, ans = 0;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) std::cin >> s[i];
    std::vector<std::vector<int>> sum(n, std::vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[i][j + 1] = sum[i][j] + (s[i][j] == '*');
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '*')
            {
                int c = i + 1, l = j - 1, r = j + 1;
                while (c < n && l >= 0 && r < m && s[c][l] == '*' &&
                       s[c][r] == '*')
                {
                    ans += (sum[c][r + 1] - sum[c][l] == r - l + 1);
                    c++, l--, r++;
                }
            }
        }
    }
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}
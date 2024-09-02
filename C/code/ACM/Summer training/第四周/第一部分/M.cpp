#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2020;
char s1[N], s2[N];
int dp[N][N];
int dvi(int i, int j)
{
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == 0)
    {
        return dp[i][j] = j;
    }
    if (j == 0)
    {
        return dp[i][j] = i;
    }
    int res = 1;
    if (s1[i] == s2[j])
    {
        res = 0;
    }
    return dp[i][j] = min(min(dvi(i - 1, j) + 1, dvi(i, j - 1) + 1), dvi(i - 1, j - 1) + res);
}
inline void slove()
{
    string str1, str2;
    cin >> str1 >> str2;
    memset(dp, -1, sizeof(dp));
    int len1 = str1.length();
    int len2 = str2.length();
    for (int i = 1; i <= len1; i++)
    {
        s1[i] = str1[i - 1];
    }
    for (int i = 1; i <= len2; i++)
    {
        s2[i] = str2[i - 1];
    }
    dvi(len1, len2);
    cout << dp[len1][len2] << endl;
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
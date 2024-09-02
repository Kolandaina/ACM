#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1000;
int dp[N][N];
inline void slove()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        for (int i = 1; i <= len1; i++)
        {
            for (int j = 1; j <= len2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[len1][len2] << endl;
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
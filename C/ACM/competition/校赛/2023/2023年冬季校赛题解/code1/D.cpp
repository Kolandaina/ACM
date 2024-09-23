#include <bits/stdc++.h>

const int inf = 1e9;

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> mp(n + 1, std::vector<int>(3));
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(3, -inf));

    for (int i = 1; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> mp[j][i];
        }
    }

    dp[1][1] = 0;
    if (mp[2][1] == 1)
        dp[2][2] = dp[2][1] = 1;
    else
        dp[2][1] = 0;
    if (mp[1][2] == 1)
        dp[2][2] = dp[1][2] = 1;
    if (mp[2][2] == 1)
        dp[2][2] = std::max({dp[2][2], dp[1][2] + 1, dp[2][1] + 1});

    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][1];
        if (mp[i][1] == 1)
        {
            dp[i][1] = std::max(dp[i][1], dp[i - 2][2] + mp[i - 1][2] + mp[i][2]) + 1;
        }
        dp[i][2] = dp[i - 1][2];
        if (mp[i][2] == 1)
        {
            dp[i][2] = std::max(dp[i][2], dp[i - 2][1] + mp[i - 1][1] + mp[i][1]) + 1;
        }
    }
    std::cout << std::max(dp[n][1], dp[n][2]);
    return 0;
}
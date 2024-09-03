#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 3e5 + 10;
int a[N];
int dp[N][2];
inline void slove() {
    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = dp[1][1] = a[1];
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - a[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + a[i]);
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}
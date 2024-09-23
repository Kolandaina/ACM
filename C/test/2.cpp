#include <bits/stdc++.h>

using namespace std;

typedef long long i64;
typedef pair<int, int> pii;

const int inf = 1000000007;
const int maxn = 1100010; // 1.1e6

inline int read() {
    int x = 0, f = 0; char ch = getchar();
    while (!isdigit(ch)) f |= (ch == 45), ch = getchar();
    while (isdigit(ch)) x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int dp[102][102][10010];
int a[102], b[102];
int main() {
    int n = read(), sum = 0;
    for (int i = 1; i <= n; ++i) {
        b[i] = read();
        a[i] = read();
        sum += a[i];
    }
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) for (int k = 0; k <= j * 100; ++k) dp[i][j][k] = -inf;
        for (int j = 0; j < i; ++j) for (int k = 0; k <= j * 100; ++k) if (dp[i - 1][j][k] >= 0) {
                    dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k]);
                    dp[i][j + 1][k + a[i]] = max(dp[i - 1][j][k] + b[i] - a[i], dp[i][j + 1][k + a[i]]);
                }
    }
    for (int j = 1; j <= n; ++j) {
        int ans = 0;
        for (int k = 0; k <= j * 100; ++k) if (dp[n][j][k] >= 0) {
                ans = max(ans, k * 2 + min(dp[n][j][k] * 2, sum - k));
            }
        double res = (ans + 0.0) / 2;
        printf("%.10lf ", res);
    }
    puts("");
    return 0;
}

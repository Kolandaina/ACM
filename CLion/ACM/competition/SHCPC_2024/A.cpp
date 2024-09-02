#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int ans = 0;
            for (int x = 0; x <= n; x++) {
                for (int y = 0; y <= m; y++) {
                    if (i == x && j == y) {
                        continue;
                    }
                    if ((i - x + j - y) % 2 != 0) {
                        continue;
                    }
                    int a = (i - j + x + y) / 2;
                    int b = (i + j - x + y) / 2;
                    int c = (x - y + i + j) / 2;
                    int d = (x + y - i + j) / 2;
                    if (0 <= a && a <= n && 0 <= b && b <= m && 0 <= c && c <= n && 0 <= d && d <= m) {
                        ans++;
                    }
                }
            }
            std::cout << ans << " \n"[j == m];
        }
    }

    return 0;
}

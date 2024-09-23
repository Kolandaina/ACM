#include<bits/stdc++.h>
#include<functional>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void solve() {
    int h, w;
    std::cin >> h >> w;
    std::vector<std::vector<int>> a(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> a[i][j];
        }
    }
    std::vector<std::vector<int>> b(h, std::vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            std::cin >> b[i][j];
        }
    }
    const int inf = (int) 1e9;
    int ans = inf;
    std::vector<int> row(h);
    iota(row.begin(), row.end(), 0);
    do {
        std::vector<int> col(w);
        iota(col.begin(), col.end(), 0);
        do {
            bool match = true;
            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    match &= (a[row[i]][col[j]] == b[i][j]);
                }
            }
            if (match) {
                int inv = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = i + 1; j < h; j++) {
                        inv += (row[i] > row[j]);
                    }
                }
                for (int i = 0; i < w; i++) {
                    for (int j = i + 1; j < w; j++) {
                        inv += (col[i] > col[j]);
                    }
                }
                ans = std::min(ans, inv);
            }
        } while (next_permutation(col.begin(), col.end()));
    } while (next_permutation(row.begin(), row.end()));
    std::cout << (ans == inf ? -1 : ans) << '\n';
}
signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) solve();
    return 0;
}

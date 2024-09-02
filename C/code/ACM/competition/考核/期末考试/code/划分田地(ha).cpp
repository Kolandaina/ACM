#include <bits/stdc++.h>
 
#define int long long
const int inf = 1e13;
 
void solved () {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> p(n);
    for(int i = 0; i < n; i++){
        std::cin >> p[i][0] >> p[i][1];
    }
    std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1));

    std::sort(p.begin(), p.end(), [&](auto A, auto B){
        return A[0] < B[0];
    });
    for(int i = 0; i < n; i++) p[i][0] = i + 1;

    std::sort(p.begin(), p.end(), [&](auto A, auto B){
        return A[1] < B[1];
    });
    for(int i = 0; i < n; i++) {
        p[i][1] = i + 1;
        f[p[i][0]][p[i][1]] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            f[i][j] += f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
        }
    }

    auto cala = [&](int x1, int y1, int x2, int y2) -> int{
        return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
    };

    int res = 0;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int l = std::min(p[i][0], p[j][0]), r = std::max(p[i][0], p[j][0]);
            res += (1 + cala(l, 1, r, (i + 1) - 1)) * (1 + cala(l, (j + 1) + 1, r, n));
        }
    }

    std::cout << ++res;
}
 
// void setIO(std::string name = "") {
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }
 
signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // setIO("wormsort");
 
    int t = 1;
    // std::cin >> t;
    for (int i = 0; i < t; ++i)
        solved ();
 
    return 0;
}
#include <bits/stdc++.h>
 
#define int long long
const int inf = 1e13;
 
void solved () {
    int n;
    std::cin >> n;
    std::vector<std::array<int, 2>> p(n);
    std::vector<std::vector<int>> f(52, std::vector<int>(52));

    for(int i = 0; i < n; i++){
        std::cin >> p[i][0] >> p[i][1];
        p[i][0]++, p[i][1]++;
        f[p[i][0]][p[i][1]] = 1;
    }
    
    for(int i = 1; i <= 51; i++){
        for(int j = 1; j <= 51; j++){
            f[i][j] += f[i][j - 1] + f[i - 1][j] - f[i - 1][j - 1];
            // std::cout << f[i][j] << ' ';
        }
        // std::cout << '\n';
    }

    auto cala = [&](int x1, int y1, int x2, int y2) -> int{
        return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
    };

    int res = 0;

    int lim = 1 << n;

    for(int i = 1; i < lim; i++){
        int a = inf, b = inf, c = -inf, d = -inf;
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if((1 << j) & i){
                cnt++;
                a = std::min(a, p[j][0]);
                b = std::min(b, p[j][1]);
                c = std::max(c, p[j][0]);
                d = std::max(d, p[j][1]);
            }
        }
        if(cala(a, b, c, d) == cnt) res++;
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
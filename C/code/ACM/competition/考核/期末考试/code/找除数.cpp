#include <bits/stdc++.h>
// #define int long long
// const int inf = 1e16;

void solved () {
    int n;
    std::cin >> n;
    int res = 1;

    for(int i = 2; i * i <= n; i++){
        int ans = 1;
        while(n % i == 0){
            ans++;
            n /= i;
        }
        res *= ans;
    }
    if(n != 1) res *= 2ll;

    std::cout << res << '\n';
}

// void setIO(std::string name = "") {
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

signed main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);

    // setIO("");

    int t = 1;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
        solved ();

    return 0;
}
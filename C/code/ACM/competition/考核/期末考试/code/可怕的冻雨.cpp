#include <bits/stdc++.h>

#define int long long
const int inf = 1e13;

void solved()
{
    int n, b;
    std::cin >> n >> b;

    std::vector<int> h(n), idx(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> h[i];
        idx[i] = i;
    }

    std::sort(idx.begin(), idx.end(),
              [&](auto A, auto B) { return h[A] < h[B]; });

    // for(int i : idx) std::cout << i << ' ';

    std::vector<std::array<int, 3>> p(b);
    for (int i = 0; i < b; i++)
    {
        std::cin >> p[i][1] >> p[i][2];
        p[i][0] = i;
    }

    std::sort(p.begin(), p.end(), [&](auto A, auto B) { return A[1] > B[1]; });

    std::vector<int> nxt(n), pre(n);
    for (int i = 0; i < n; i++) nxt[i] = i + 1, pre[i] = i - 1;

    std::vector<int> res(b);
    for (int i = 0, j = n - 1, ans = 1; i < b; i++)
    {
        while (j >= 0 && h[idx[j]] > p[i][1])
        {
            int a = pre[idx[j]], b = nxt[idx[j]];
            nxt[a] = b;
            pre[b] = a;
            ans = std::max(ans, b - a);
            j--;
        }
        res[p[i][0]] = (p[i][2] >= ans);
    }
    for (auto i : res) std::cout << i << '\n';
}

// void setIO(std::string name = "") {
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // setIO("");

    int t = 1;
    // std::cin >> t;
    for (int i = 0; i < t; ++i) solved();

    return 0;
}
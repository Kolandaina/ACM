
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    int k;
    std::cin >> k;
    while (k--)
    {
        std::vector<int> b(n);
        for (int i = 0; i < n; i++) std::cin >> b[i];
        int res = 0;
        for (int i = 0; i < n; i++)
            if (a[i] == b[i])
                res++;
            else if (b[i] == 0)
                continue;
            else if (a[i] != b[i])
                res -= 100;
        if (res > 0)
            std::cout << "Da Jiang!!!" << endl;
        else
            std::cout << "Ai Ya" << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}
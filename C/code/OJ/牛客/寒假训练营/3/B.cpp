#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        std::cin >> x;
    }
    if (n % 2 == 0)
        std::cout << "zn" << endl;
    else
        std::cout << "qcjj" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}
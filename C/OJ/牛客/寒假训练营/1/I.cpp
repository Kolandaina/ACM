#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{

    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        if (x <= 9 && x >= -9 && y <= 9 && y >= -9)
        {
            ans++;
        }
    }
    if (ans <= n / 90)
        std::cout << "bit-noob" << endl;
    else
        std::cout << "buaa-noob" << endl;
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
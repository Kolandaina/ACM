#include <bits/stdc++.h>
#define int  long long
#define endl "\n"
inline void slove()
{
    int n, a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        std::cin >> x;
        if (x == 3) a++;
        if (x == 6) b++;
        if (x == 7) c++;
        if (x == 2) d++;
        if (x == 10) e++;
        if (x == 8) f++;
    }
    std::cout << a * b + c * d + e * f << endl;
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
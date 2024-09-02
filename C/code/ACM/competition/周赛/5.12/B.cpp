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
    int num = n % 3;
    if (num == 0)
    {
        for (int i = 0; i < n / 3; i++) std::cout << "A";
        for (int i = 0; i < n / 3; i++) std::cout << "B";
        for (int i = 0; i < n / 3; i++) std::cout << "C";
        std::cout << (n / 3) * (n / 3) * (n / 3) << endl;
    }
    else if (num == 1)
    {
        std::cout << "A";
        n -= num;
        for (int i = 0; i < n / 3; i++) std::cout << "A";
        for (int i = 0; i < n / 3; i++) std::cout << "B";
        for (int i = 0; i < n / 3; i++) std::cout << "C";
        std::cout << endl;
        std::cout << (n / 3 + 1) * (n / 3) * (n / 3) << endl;
    }
    else if (num == 2)
    {
        std::cout << "A";
        n -= num;
        for (int i = 0; i < n / 3; i++) std::cout << "A";
        std::cout << "B";
        for (int i = 0; i < n / 3; i++) std::cout << "B";
        for (int i = 0; i < n / 2; i++) std::cout << "C";
        std::cout << endl;
        std::cout << (n / 3 + 1) * (n / 3 + 1) * (n / 3) << endl;
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
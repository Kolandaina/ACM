#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        int a, b;
        for (int i = 0; i < n + 1; i++)
            std::cin >> a >> b;
        std::cout << (n - 4) / 2 << '\n';
    }
    return 0;
}


#include <bits/stdc++.h>
int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(5));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 5; j++)
            std::cin >> a[i][j];
    int l = 0, r = 1e9 + 1;
    auto check = [&](int x) -> bool
    {
        std::set<int> s;
        for (int i = 0; i < n; i++)
        {
            int tot = 0;
            for (int j = 0; j < 5; j++)
            {
                tot <<= 1;
                if (a[i][j] >= x)
                    tot |= 1;
            }
            s.insert(tot);
        }
        for (int x : s)
            for (int y : s)
                for (int z : s)
                {
                    if ((x | y | z) == 31)
                        return 1;
                }
        return 0;
    };
    while (l + 1 < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    std::cout << l;
    return 0;
}

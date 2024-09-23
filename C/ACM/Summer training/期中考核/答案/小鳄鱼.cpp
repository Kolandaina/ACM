#include <bits/stdc++.h>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    int t;
    std::cin >> t;
    while(t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> vis(10), res;
        for(int i = 9; i > 0; i--)
        {
            if(i > n) continue;
            if(vis[i] == 0)
            {
                vis[i] = 1;
                n -= i;
                res.push_back(i);
            }
        }
        for(int i = res.size() - 1; i >= 0; i--) std::cout << res[i];
        std::cout << '\n';
    }

    return 0;
}

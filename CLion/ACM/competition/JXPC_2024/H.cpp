#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove()
{
    int n,m,a,b;
    std::cin>>n>>m>>a>>b;
    std::vector<std::vector<int>> g(n+1,std::vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            std::cin>>g[i][j];
        }
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
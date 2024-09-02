
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int x,y;
    std::cin>>x>>y;
    std::cout<<std::max((y+1)/2,(4*y+x+14)/15)<<endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std:: cin >> t;
    while (t--) slove();
    return 0;
}
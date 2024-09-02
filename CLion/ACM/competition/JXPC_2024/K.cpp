#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 998244353;
const int INF = 0x3f3f3f3f3f3f3f3f;
int ksm(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b&1) res = res*a%mod;
        a = a*a%mod;
        b>>=1;
    }
    return res;
}
inline void slove()
{
    int n;
    std::cin>>n;
    std::cout<<ksm(2,n-1)<<endl;
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
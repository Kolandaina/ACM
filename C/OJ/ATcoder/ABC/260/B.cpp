#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
struct node
{
    int x;
    int a,b;
    int sum;
}f[1010];
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        if(s1.a == s2.a) return s1.x < s2.x;
        return s1.a > s2.a;
    }
};
struct node2
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        if(s1.b == s2.b) return s1.x < s2.x;
        return s1.b > s2.b;
    }
};
struct node3
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        if(s1.sum == s2.sum) return s1.x < s2.x;
        return s1.sum > s2.sum;
    }
};
inline void slove()
{
    int n,x,y,z;
    vector<int> a;
    cin >> n >> x >> y >> z;
    for(int i = 1; i <= n; i++) cin>>f[i].a;
    for(int i = 1; i <= n; i++)
    {
        cin>>f[i].b;
        f[i].x = i;
        f[i].sum = f[i].a + f[i].b;
    }
    sort(f + 1, f + n + 1,node1());
    sort(f + 1 + x, f + n + 1,node2());
    sort(f + 1 + x + y, f + n + 1,node3());
    for(int i = 1; i <= x + y + z; i++) a.push_back(f[i].x);
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) cout<<a[i]<<endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}
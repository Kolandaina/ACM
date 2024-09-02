#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int p = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

int a[p],now[p],ad[p];
map<int,int>mp;
inline void slove()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int f=-1,f2=-1;
    for(int i=0;i<k;i++){
        int x=a[now[i-1]%n];
        if(i>0)ad[i]=ad[i-1]+x;
        else ad[i]=x;
        for(int j=0;j*n<=ad[i];j++){
            if(mp[ad[i]-j*n]){
                f=ad[i]-j*n;
                f2=i;
                break;
            }
        }
        if(f!=-1)break;
    }
    int id=0;
    for(int i=0;i<=n;i++)
    {
        if (ad[i] == f)id = i+1;
    }
    int num=n%
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
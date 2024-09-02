// #include<bits/stdc++.h>
// using namespace std;
// int ans[100000];
// int main()
// {
//     int n,a[100000];
//     cin>>n;
//     for(int i=0;i<n;i++) cin>>a[i];
//     if(n==1)
//     {
//         cout<<1;
//         return 0;
//     }
//     for(int i=0;i<n;i++)
//     {
//         int s=0;
//         for(int j=0;j<n;j++)
//         {
//             if(abs(a[i]-a[j])<=9&&a[i]!=a[j]) s++;
//         }
//         ans[i]=s;
//     }
//     int s=*max_element(ans,ans+n);
//     cout<<s;
//     return 0;
// }
#include <bits/stdc++.h>
#define pii pair<int, int>
#define ios ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for (int i = a; i <= b; ++i)
using namespace std;
using i64 = long long;
const int N = 2e5 + 10;
int s[N];
void solve()
{
    int n, x;
    cin >> n;
    const int del = 100001;
    rep(i, 1, n)
    {
        cin >> x;
        if (x >= 0)
            s[del + x]++;
        else
            s[abs(x)]++;
    }
    rep(i, 1, N - 1) s[i] += s[i - 1];
    int mx = 0;
    rep(i, 1, (N - 1) - 9)
    {
        mx = max(mx, s[i + 9] - s[i - 1]);
    }
    cout << mx << "\n";
}
signed main()
{
    ios;
    solve();
    return 0;
}
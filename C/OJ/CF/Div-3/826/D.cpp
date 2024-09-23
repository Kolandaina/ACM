#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
bool fun(vector<int> v, int k)
{
    if (v.size() == 1)
        return true;
    vector<int> vv;
    for (int i = 0; i < v.size(); i += 2)
    {
        if (abs(v[i] - v[i + 1]) == k)
            vv.push_back(v[i] + v[i + 1]);
        else
            return false;
    }
    return fun(vv, k * 4);
}
int sum(vector<int> v, int ans)
{
    if (v.size() == 1)
        return ans;
    vector<int> vv;
    for (int i = 0; i < v.size(); i += 2)
    {
        if (v[i] > v[i + 1])
        {
            ans++;
        }
        vv.push_back(v[i] + v[i + 1]);
    }
    return sum(vv, ans);
}
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    bool flag = fun(a, 1);
    if (!flag)
        cout << -1 << endl;
    else
    {
        int ans = sum(a, 0);
        cout << ans << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}
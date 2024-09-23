#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, d;
    cin >> n >> d;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int len = a.size();
    bool flag = true;
    for (int i = 1; i < len; i++)
    {
        if (a[i] - a[i - 1] <= d)
        {
            cout << a[i] << endl;
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << -1 << endl;
    }
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}
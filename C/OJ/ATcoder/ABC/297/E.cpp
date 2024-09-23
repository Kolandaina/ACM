#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, k, a[10];
    priority_queue<int, vector<int>, greater<int>> q;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    q.push(0);
    k++;
    int nx = -1;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        if (u == nx)
            continue;
        k--, nx = u;
        if (!k)
            break;
        for (int i = 0; i < n; i++)
            q.push(u + a[i]);
    }
    cout << nx << endl;
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
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define endl "\n"
int n, m;
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        scanf("%d %d", &n, &m);
        vector<int> in(n + 10), ans(n + 10);
        vector<vector<int>> g(n + 10);
        for (int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
            in[y]++;
        }
        priority_queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (!in[i])
            {
                q.push(i);
            }
        }
        int num = 0;
        while (!q.empty())
        {
            int x = q.top();
            q.pop();
            ans[num++] = x;
            for (auto e : g[x])
            {
                in[e]--;
                if (!in[e])
                {
                    q.push(e);
                }
            }
        }
        long long res = 0;
        int minn = 1e9;
        for (int i = 0; i < n; i++)
        {
            minn = min(minn, ans[i]);
            res += minn;
        }
        cout << res << endl;
    }
    return 0;
}
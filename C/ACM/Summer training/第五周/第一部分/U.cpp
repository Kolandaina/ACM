#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 100;
vector<vector<int>> g(N);
int in[N], ans[N], inn[N];
bool vis[N];
int n, m, s, sum;
int topusort()
{
    sum = 0;
    bool one = false, two = false;
    queue<int> q;
    for (int i = 1; i <= 26; i++)
    {
        inn[i] = in[i];
        if (!inn[i] && vis[i])
        {
            if (!one)
                one = true;
            else
                two = true;
            q.push(i);
            ans[++sum] = i;
        }
    }
    if (q.empty())
        return 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        one = false;
        for (auto e : g[x])
        {
            inn[e]--;
            if (!inn[e])
            {
                q.push(e);
                if (!one)
                    one = true;
                else
                    two = true;
                ans[++sum] = e;
            }
        }
    }
    if (sum != s)
        return 1;
    if (two)
        return 2;
    return 0;
}
inline void slove()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        char a, b, c;
        cin >> a >> b >> c;
        x = a - 64, y = c - 64;
        if (!vis[x])
        {
            vis[x] = true;
            s++;
        }
        if (!vis[y])
        {
            vis[y] = true;
            s++;
        }
        g[x].push_back(y);
        in[y]++;
        if (topusort() == 1)
        {
            cout << "Inconsistency found after " << i << " relations.";
            return;
        }
        if (sum == n && !topusort())
        {
            cout << "Sorted sequence determined after " << i << " relations: ";
            for (int j = 1; j <= n; j++)
                cout << char(ans[j] + 64);
            cout << ".";
            return;
        }
    }
    printf("Sorted sequence cannot be determined.");
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
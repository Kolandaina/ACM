#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define int long long
#define endl "\n"
int mp[501][501];
void sol()
{
    int x, y;
    cin >> x >> y;
    queue<pair<int, int>> q;
    q.push({1, 1});
    int ci = 3e5;
    memset(mp, 0, sizeof(mp));
    while (!q.empty() && ci--)
    {
        auto u = q.front();
        q.pop();
        if ((u.first == x && u.second == y) || (u.first == y && u.second == x))
        {
            cout << "Yes" << endl;
            return;
        }
        int xx = u.first, yy = u.second;
        // cout << xx << " " << yy << endl;
        if (xx >= 500 || yy >= 500 || xx < 0 || yy < 0)
        {
            continue;
        }
        if (mp[xx][yy] == 1)
        {
            continue;
        }
        mp[xx][yy] = 1;
        q.push({xx * 2, yy});
        q.push({xx, yy * 2});
        q.push({xx - yy, yy});
        q.push({xx, yy - xx});
    }
    cout << "No" << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        sol();
    }
}
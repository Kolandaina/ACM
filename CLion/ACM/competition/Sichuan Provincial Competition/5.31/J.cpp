#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 5e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int M = 1600;
using namespace std;
int f[M][M];
int h, w, n, m;
vector<int> pos;
bool check(int x, int y, int flag)
{

    int cnt1 = lower_bound(pos.begin(), pos.end(), y) - pos.begin();
    if (cnt1 != 0)
    {
        cnt1--;
        if (flag == 1)
        {
            if (f[x][pos[cnt1]] == 1) return true;
        } else
        {
            if (f[pos[cnt1]][x] == 1) return true;
        }
    }
    int cnt2 = upper_bound(pos.begin(), pos.end(), y) - pos.begin();
    if (cnt2 != pos.size())
    {
        if (flag == 1)
        {
            if (f[x][pos[cnt2]] == 1) return true;
        } else
        {
            if (f[pos[cnt2]][x] == 1) return true;
        }

    }
    return false;
}

inline void slove()
{
    std::cin >> h >> w >> n >> m;///行，列
    for (int i = 0; i < n; i++)
    {
        int x, y;
        std::cin >> x >> y;
        f[x][y] = 1;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        std::cin >> x >> y;
        f[x][y] = 2;
    }
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (f[i][j] == 1 || f[i][j] == 2)pos.push_back(j);
        }
        for (int j = 1; j <= w; j++)
        {
            if (f[i][j] == 1)continue;
            if (f[i][j] == 2)continue;
            if (f[i][j] == 3) continue;
            if (check(i, j, 1))f[i][j] = 3;
        }
        pos.clear();
    }
    for (int i = 1; i <= w; i++)
    {

        for (int j = 1; j <= h; j++)
        {
            if (f[j][i] == 1 || f[j][i] == 2) pos.push_back(j);
        }
        for (int j = 1; j <= h; j++)
        {
            if (f[j][i] == 1)continue;
            if (f[j][i] == 2)continue;
            if (f[j][i] == 3) continue;
            if (check(i, j, 2))f[j][i] = 3;
        }
        pos.clear();
    }
    int ans = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (f[i][j] == 1 || f[i][j] == 3) ans++;
        }
    }
    std::cout<<ans<<endl;
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
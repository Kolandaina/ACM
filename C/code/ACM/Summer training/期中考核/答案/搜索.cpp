#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 1e6 + 9, M = 5e3 + 9, INF = 0x3f3f3f3f;
int t, n, m, num, sum, ans, x, y, k, z, flag, dx, dy;

signed main()
{
    ans = 0;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];//a����ǵ�ͼ
    vector<int> b(4), d(4);
    vector<vector<int>> c(5, vector<int>(2));//��ʼ�㣬�������ߣ��յ�
    for (int i = 0; i < 5; i++)
        cin >> c[i][0] >> c[i][1];
    for (int i = 0; i < 5; i++)//��Ŀ��1��n����������0��n�����Լ�һ����
        c[i][0]--, c[i][1]--;
    for (int i = 1; i <= 3; i++)
        cin >> d[i];
    auto bfs = [&](pair<int, int> S, int f) -> int
    {//���ߵ��յ�����·
        vector<vector<int>> next(4, vector<int>(2));
        next = {{1,  0},
                {0,  1},
                {-1, 0},
                {0,  -1}};
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m));
        vis[S.first][S.second] = 1;
        q.push(S);
        while (!q.empty())
        {
            x = q.front().first;
            y = q.front().second;
            if (x == c[4][0] && y == c[4][1])
            {
                return (vis[x][y] - 1) * f;
            }
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                dx = x + next[i][0];
                dy = y + next[i][1];
                if (dx >= 0 && dx < n && dy >= 0 && dy < m && a[dx][dy] != '#' && !vis[dx][dy])
                {
                    vis[dx][dy] = vis[x][y] + 1;
                    q.push({dx, dy});
                }
            }
        }
        return INF;
    };
    function<void(int, pair<int, int>, int, int)> dfs = [&](int sum, pair<int, int> S, int f, int q) -> void
    {//�õ�dfsö���������ߵ���ȡ˳��Ҳ���Ա���ö��
        if (q == 3)
        {
//            cout<<bfs(S,f)<<" ";
            ans = min(bfs(S, f) + sum, ans);
//            cout<<sum<<" \n";
            return;
        }
        for (int i = 1; i <= 3; i++)
        {
            if (b[i] == 0)
            {
                //cout<<i<<' ';
                b[i] = 1;
                dfs(sum + (abs(S.first - c[i][0]) + abs(S.second - c[i][1])) * f, {c[i][0], c[i][1]}, f + d[i], q + 1);
                b[i] = 0;
            }

        }
    };
    ans = INF;
    dfs(0, {c[0][0], c[0][1]}, 1, 0);
    cout << ans << '\n';
    return 0;
}

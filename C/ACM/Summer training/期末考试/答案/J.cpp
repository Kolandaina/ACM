#include <iostream>
#include <vector>
#include <queue>

typedef long long LL;

const int N = 1e5 + 10, Mod = 1e9 + 7;

std::vector<int> ne[N];
int f[N][20], st[N];
LL cnt[N];

void bfss()
{
    std::queue<int> que;
    que.push(0);
    cnt[0] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i < ne[u].size(); i++)
        {
            int j = ne[u][i];
            cnt[j] = cnt[j] * cnt[u] % Mod;
            que.push(j);
        }
    }
}

void bfs()
{
    std::queue<int> que;
    que.push(0);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        // std::cout << u << " #--> " << std::endl;
        for (int i = 0; i < ne[u].size(); i++)
        {
            int j = ne[u][i];
            f[j][0] = u;
            // std::cout << j << " " << f[j][0] << std::endl;
            st[j] = st[u] + 1;
            for (int k = 1; k < 20; k++)
            {
                f[j][k] = f[f[j][k - 1]][k - 1];
                // std::cout << j << " " << k << " " << f[4][0] << std::endl;
            }

            que.push(j);
        }
    }
}

bool lca(int a, int b)
{
    // std::cout << "--> " << st[a] << " " << st[b] << std::endl;
    // std::cout << f[b][0] << std::endl;
    if (st[a] > st[b])
        return false;
    for (int i = 20; i >= 0; i--)
    {
        if (st[f[b][i]] >= st[a])
            b = f[b][i];
    }
    // std::cout << b << std::endl;
    // std::cout << f[b][0] << std::endl;
    // std::cout << "@ " << a << " " << b << std::endl;
    return a == b;
}

LL qmi(LL a, int b)
{
    LL res = 1;
    while (b)
    {
        if (b % 2)
            res = a * res % Mod;
        b /= 2;
        a = a * a % Mod;
    }
    return res;
}

int main()
{
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int n, q;
    std::cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        std::cin >> a >> b;
        ne[a].push_back(i);
        cnt[i] = b;
        if (!a)
            cnt[i] = 1;
    }
    cnt[0] = 1;

    bfss();
    bfs();
    // std::cout << f[4][0] << std::endl;
    // std::cout << 1 << std::endl;
    while (q--)
    {
        int a, b;
        std::cin >> a >> b;
        // std::cout << "# " << a << " " << b << std::endl;
        // std::cout << "# " << lca(a, b) << std::endl;
        if (lca(a, b))
            std::cout << cnt[b] * qmi(cnt[a], Mod - 2) % Mod << std::endl;
        else
            std::cout << 0 << std::endl;
    }
    return 0;
}
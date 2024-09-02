#include <iostream>
#include <queue>

const int N = 520;

std::string mp[N][N];
bool st[N][N];
int ne[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

struct node
{
    int y, x;
    std::string str;

    bool operator<(const node &p) const
    {
        if (str.size() != p.str.size())
            return str.size() > p.str.size();
        return str > p.str;
    }
};

int n, m;

bool check(int y, int x)
{
    return y >= 1 && y <= n && x >= 1 && x <= m && !st[y][x];
}

std::string bfs()
{

    std::priority_queue<node, std::vector<node>> que;
    node u = {1, 1, ""};
    if (mp[1][1] != "0")
        u.str = mp[1][1];
    que.push(u);
    st[1][1] = true;
    while (!que.empty())
    {
        u = que.top();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int y = u.y + ne[i][0];
            int x = u.x + ne[i][1];
            if (check(y, x))
            {
                std::string str = u.str;
                if (u.str != "" || mp[y][x] != "0")
                    str += mp[y][x];
                st[y][x] = true;
                que.push({y, x, str});
                if (y == n && x == m)
                {
                    if (str == "")
                        str = "0";
                    return str;
                }
            }
        }
    }

    return mp[1][1];
}

int main()
{

    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            std::cin >> mp[i][j];
    std::cout << bfs() << std::endl;
    return 0;
}
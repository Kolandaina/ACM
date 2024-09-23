#include <bits/stdc++.h> //万能大法好
using namespace std;
int a[1000][1000], m, n;                                                      // a是雷图，mn是边界
bool booka[1000][1000];                                                       // 联通快时判重
int xz[8] = {-1, -1, -1, 0, 0, 1, 1, 1}, yz[8] = {-1, 0, 1, -1, 1, -1, 0, 1}; // 八联通！！！
int bv3, lt;                                                                  // 第一个3bv，lt是联通快的数量
void dfs(int x, int y)                                                        // 联通快
{
    for (int i = 0; i < 8; i++)
    {
        int xx = x + xz[i], yy = y + yz[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == 0 && !booka[xx][yy]) // 判断边界与重复
        {
            booka[xx][yy] = true; // 打标记
            dfs(xx, yy);
        }
    }
}
void b(int x, int y) // 初始化雷图用的，把格子里填数字
{
    for (int p = 0; p < 8; p++)
    {
        int i = x + xz[p], j = y + yz[p];
        if (i >= 0 && i < n && j >= 0 && j < m && a[i][j] != -1)
            a[i][j]++;
    }
}
int iff(int x, int y) // 判断周围八格是否有空格
{
    for (int i = 0; i < 8; i++)
    {
        int xx = x + xz[i];
        int yy = y + yz[i];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && a[xx][yy] == 0) // 判空格
            return 0;
    }
    return 1;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                a[i][j] = -1; // 读入，把雷标记为-1，便于区分数字为 1的无雷格
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == -1)
                b(i, j); // 把有雷格周围八格数字自增
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] != 0 && a[i][j] != -1 && iff(i, j))
                bv3++; // 周围八格无雷的数字的数量
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0 && !booka[i][j])
            {
                lt++; // 联通快数量
                dfs(i, j);
            }
        }
    }
    bv3 += lt;
    cout << bv3; // 输出答案
    return 0;
}
#include <cstring>
#include <iostream>
using namespace std;
int a[10], n, k, first;
int sum;
char map[10][10];
void dfs(int x, int step)
{
    int j;
    if (step == 0)
    {
        sum++;
        return;
    }
    if (x >= n)
    {
        return;
    }
    for (j = 0; j < n; j++)
    {
        if (!a[j] && map[x][j] == '#')
        {
            a[j] = 1;
            dfs(x + 1, step - 1);
            a[j] = 0;
        }
    }
    dfs(x + 1, step);
}
int main()
{
    int i, j;
    while (cin >> n >> k && n != -1 && k != -1)
    {
        memset(a, 0, sizeof(a));
        sum = 0;
        for (i = 0; i < n; i++)
            cin >> map[i];
        dfs(0, k);
        cout << sum << endl;
    }
    return 0;
}

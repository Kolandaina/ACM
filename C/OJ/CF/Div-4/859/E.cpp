#include <bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll sum[200200];
ll read()
{
    ll x = 0, f = 1;
    char ch;
    ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 1) + (x << 3) + ch - '0';
        ch = getchar();
    }
    return x * f;
}
void solve()
{
    int n = read();
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        sum[i] = 0;
        sum[i] = sum[i - 1] + x; // 预处理求前缀和
    }
    int l = 1, r = n;
    while (l < r)
    { // 还没确定到具体堆的编号
        int mid = l + r >> 1;
        cout << "? " << mid - l + 1;
        for (int i = l; i <= mid; i++)
        { // 取前二分之一
            cout << " " << i;
        }
        cout << endl;
        fflush(stdout);
        int get = read();
        if (sum[mid] - sum[l - 1] != get)
        { // 如果匹配不上说明目标堆在前半部分
            r = mid;
        }
        else
            l = mid + 1; // 否则在后半部分
    }
    cout << "! " << r << endl;
    fflush(stdout); // 记得刷新缓冲区
}
int main()
{
    t = read();
    while (t--)
    {
        solve();
    }
    return 0;
}

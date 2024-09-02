#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n, a[N], b[N];
int temp[N], res[N];
int maxn, max_sum;
int ans;
bool fun()
{
    sort(temp + 1, temp + n + 1);
    if (max_sum != n || temp[1] < 0)
    {
        return true;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (temp[i] == temp[i - 1])
        {
            return true;
        }
    }
    return false;
}
bool cmp(int x, int y)
{
    return b[x] < b[y];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        res[i] = i;
        temp[i] = b[i] = b[i - 1] + a[i];
        if (maxn < temp[i])
        {
            maxn = temp[i];
            max_sum = i;
        }
    }
    if (fun())
    {
        cout << "-1" << endl;
        return 0;
    }
    sort(res + 1, res + n + 1, cmp);
    for (int i = 1; i < n; ++i)
    {
        b[res[i]] = i;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (b[i] != i)
        {
            swap(res[b[i]], res[i]);
            swap(b[res[b[i]]], b[i]);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
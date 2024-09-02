#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 10;
int n, k;
int a[maxn], b[maxn], id1[maxn], id2[maxn];
bool cmp1(int i, int j)
{
    return a[i] < a[j];
}
bool cmp2(int i, int j)
{
    return b[i] < b[j];
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], id1[i] = i;
    for (int i = 1; i <= n; i++)
        cin >> b[i], id2[i] = i;
    sort(id1 + 1, id1 + n + 1, cmp1);
    sort(id2 + 1, id2 + n + 1, cmp2);
    for (int i = 1; i <= n; i++)
    {
        a[id1[i]] = b[id2[i]];
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    cout << endl;
}
signed main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}

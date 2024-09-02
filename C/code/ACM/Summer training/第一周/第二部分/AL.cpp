#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N], b[N];
inline void slove()
{
    int n, k, m;
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &m);
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    set<int> st;
    int o = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (st.count(a[o % n]))
        {
            b[o % n]++;
            st.erase(a[o % n]);
        }
        else
        {
            st.insert(a[o % n]);
        }
        o++;
    }
    int cnt = m / (2 * n);
    for (int i = 0; i < n; i++)
    {
        b[i] *= cnt;
    }
    for (int i = 0; i < m - cnt * 2 * n; i++)
    {
        if (st.count(a[o % n]))
        {
            b[o % n]++;
            st.erase(a[o % n]);
        }
        else
        {
            st.insert(a[o % n]);
        }
        o++;
    }
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            printf("%d", b[i]);
        }
        else
        {
            printf("%d ", b[i]);
        }
    }
    cout << endl;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        slove();
    }
    return 0;
}
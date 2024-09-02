#include <bits/stdc++.h>
using namespace std;
const int M = 1e5;
#define int long long
struct node
{
    int a;
    int b;
};
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        if (s1.a == s2.a)
        {
            return s1.b < s2.b;
        }
        return s1.a < s2.a;
    }
};
struct node2
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.b < s2.b;
    }
};
signed main()
{
    int T, p = 1;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        node f[M];
        for (int i = 0; i < n; i++)
        {
            cin >> f[i].a;
            f[i].b = i;
        }
        sort(f, f + n, node1());
        for (int i = 0; i < n; i += p)
        {
            p = 1;
            for (int j = i + 1; j <= n; j++)
            {
                if (f[i].a == f[j].a)
                {
                    f[j].a = -2147483659;
                    p++;
                }
                else break;
            }
        }
        sort(f, f + n, node2());
        for (int i = 0; i < n; i++)
        {
            if (f[i].a != -2147483659)
            {
                cout << f[i].a << " ";
            }
        }
        cout << endl;
    }
}
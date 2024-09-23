#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    int b;
};
struct node1
{
    bool operator()(const node &a, const node &b)
        const
    {
        return a.a < b.a;
    }
};
int main()
{
    int m, n;
    cin >> m >> n;
    node f[1000];
    for (int i = 0; i < n + m; i++)
    {
        cin >> f[i].a >> f[i].b;
    }
    sort(f, f + n + m, node1());
    for (int i = 0; i < n + m; i++)
    {
        cout << f[i].a << " " << f[i].b << endl;
    }
    return 0;
}
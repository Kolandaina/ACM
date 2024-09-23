#include <bits/stdc++.h>
using namespace std;
int sum = 0, o = 1;
struct node
{
    int a;
    int b;
};
node f[120];
node q[120];
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        if (s1.a == s2.a)
        {
            return s1.b < s2.b;
        }
        return s1.a > s2.a;
    }
};
bool div(int x)
{
    for (int i = 0; i < o; i++)
    {
        if (x + 1 == q[i].b || x - 1 == q[i].b)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].a;
        f[i].b = i;
    }
    sort(f, f + n, node1());
    q[0].a = f[0].a, q[0].b = f[0].b;
    sum = f[0].a;
    for (int i = 1; i < n; i++)
    {
        if (div(f[i].b))
        {
            q[o].a = f[i].a;
            q[o++].b = f[i].b;
            sum += f[i].a;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << f[i].a << " " << f[i].b << endl;
    }
    cout << sum << endl;
    return 0;
}
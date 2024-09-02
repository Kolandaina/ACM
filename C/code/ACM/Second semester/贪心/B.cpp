#include <bits/stdc++.h>
using namespace std;
struct node
{
    double a;
    double b;
    double c;
};
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.c > s2.c;
    }
};
int main()
{
    int t, m;
    cin >> t >> m;
    node f[105];
    for (int i = 0; i < t; i++)
    {
        cin >> f[i].a >> f[i].b;
        f[i].c = f[i].b / f[i].a;
    }
    sort(f, f + t, node1());
    double sum = 0;
    for (int i = 0; i < t; i++)
    {
        if (m > f[i].a)
        {
            m -= f[i].a;
            sum += f[i].b;
        }
        else
        {
            sum += m * f[i].c;
            break;
        }
    }
    printf("%.2lf", sum);
    return 0;
}
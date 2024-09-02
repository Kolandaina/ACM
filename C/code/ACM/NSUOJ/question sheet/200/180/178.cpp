#include <bits/stdc++.h>
using namespace std;
double x, y, z;
struct node
{
    char name[20];
    char id[20];
    int a;
    int b;
    int c;
    double d;
};
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.d > s2.d;
    }
};
int main()
{
    node f[1000];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i].id >> f[i].name >> f[i].a >> f[i].b >> f[i].c;
        f[i].d = 1.0 * (f[i].a + f[i].b + f[i].c) / 3;
        x += f[i].a, y += f[i].b, z += f[i].c;
    }
    sort(f, f + n, node1());
    cout << x / n << " " << y / n << " " << z / n << endl;
    cout << f[0].id << " " << f[0].name << " " << f[0].a << " " << f[0].b << " " << f[0].c << endl;
    return 0;
}
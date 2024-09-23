#include <bits/stdc++.h>
using namespace std;
struct node
{
    int a;
    int b;
    int c;
};
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        return s1.c < s2.c;
    }
};
int main()
{
    int n;
    cin >> n;
    node m[50000];
    for (int i = 0; i < n; i++)
    {
        cin >> m[i].a >> m[i].b >> m[i].c;
    }
    sort(m, m + n, node1());
    double ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        ans += sqrt(pow((m[i].a - m[i + 1].a), 2) + pow((m[i].b - m[i + 1].b), 2) + pow((m[i].c - m[i + 1].c), 2));
    }
    printf("%.3lf", ans);
    return 0;
}

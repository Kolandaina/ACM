#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

#define gc() getchar()
#define digit(x) (x >= '0' && x <= '9')
int read()
{
    int x = 0, f = 1; char c = gc();
    while (!digit(c)) {if (c == '-') f = -1; c = gc();}
    while (digit(c)) x = (x << 3) + (x << 1) + c - '0', c = gc();
    return x * f;
}

int f[N];
int fa[N];
int Min[N];

queue<int> leaf;

int r[N];
vector<int> V[N];

int n;

int main()
{
    n = read();
    for (int i = 2; i <= n; i++)
    {
        fa[i] = read();
        V[fa[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!V[i].size())
        {
            leaf.push(i);
            f[1]++;
            Min[i] = 1;
        }
    while (!leaf.empty())
    {
        int i = leaf.front(); leaf.pop();
        if (i == 1) continue;
        while (fa[i] != 1 && V[fa[i]].size() == 1)
        {
            f[Min[i]]--;
            Min[fa[i]] = Min[i] + 1;
            f[Min[fa[i]]]++;
            i = fa[i];
        }
        if (i == 1) continue;
        if (V[fa[i]].size() > r[fa[i]] + 1) {r[fa[i]]++; continue;}
        int M = V[fa[i]][0];
        for (int j = 1; j < V[fa[i]].size(); j++)
        {
            if (Min[V[fa[i]][j]] < Min[M]) M = V[fa[i]][j];
        }
        if (fa[i] != 1)
        {
            f[Min[M]]--;
            Min[fa[i]] = Min[M] + 1;
            f[Min[fa[i]]]++;
        }
        leaf.push(fa[i]);
    }
    int ans1, ans2;
    for (int i = 1; i <= n; i++) if (f[i]) {ans1 = i; break;}
    for (int i = n; i >= 1; i--) if (f[i]) {ans2 = i; break;}

    printf("%d\n", ans2 - ans1);
    return 0;
}

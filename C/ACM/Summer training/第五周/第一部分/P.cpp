#include <bits/stdc++.h>
using namespace std;
const int maxn = 11000;
int pre[maxn], in[maxn], post[maxn], l[maxn], r[maxn], best_sum, best, n;
int bulid(int l1, int r1, int l2, int r2)
{
    if (l1 > r1)
        return 0;
    int root = post[r2];
    int p = l1;
    while (in[p] != root)
        p++;
    int cnt = p - l1;
    ;
    l[root] = bulid(l1, p - 1, l2, l2 + cnt - 1);
    r[root] = bulid(p + 1, r1, l2 + cnt, r2 - 1);
    return root;
}
void dfs(int cur, int sum)
{
    sum += cur;
    if (!l[cur] && !r[cur])
    {
        if (sum < best_sum || (sum == best_sum && cur < best))
        {
            best_sum = sum;
            best = cur;
        }
    }
    if (l[cur])
        dfs(l[cur], sum);
    if (r[cur])
        dfs(r[cur], sum);
}

int main()
{
    while (scanf("%d", &in[0]) != EOF)
    {
        int k1 = 1, k2 = 0;
        while (true)
        {
            char ch = getchar();
            if (ch == '\n')
                break;
            scanf("%d", &in[k1++]);
        }
        while (true)
        {
            scanf("%d", &post[k2++]);
            char ch = getchar();
            if (ch == '\n')
                break;
        }
        n = k1;
        bulid(0, n - 1, 0, n - 1);
        best_sum = best = INT_MAX;
        dfs(post[n - 1], 0);
        printf("%d\n", best);
    }
    return 0;
}
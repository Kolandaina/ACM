#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int trie[N * 32][2], tot = 1;
void insert(int x)
{
    int p = 1;
    for (int i = 31; i >= 0; i--)
    {
        int t = (x >> i) & 1;
        if (!trie[p][t])
            trie[p][t] = ++tot;
        p = trie[p][t];
    }
}
int search(int x)
{
    int p = 1;
    int res = 0;
    for (int i = 31; i >= 0; i--)
    {
        int t = (x >> i) & 1;
        if (t == 1)
        {
            if (trie[p][0])
            {
                p = trie[p][0];
                res += (1 << i);
            }
            else
                p = trie[p][1];
        }
        else if (t == 0)
        {
            if (trie[p][1])
            {
                p = trie[p][1];
                res += (1 << i);
            }
            else
                p = trie[p][0];
        }
    }
    return res;
}
int a[N];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, search(a[i]));
    }
    printf("%d\n", res);
    return 0;
}
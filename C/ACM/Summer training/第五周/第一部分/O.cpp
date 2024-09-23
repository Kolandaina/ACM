#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int MAXN = 100;
int pre[MAXN], in[MAXN], post[MAXN];
int k = 0;
int t = 1;
int o = 1;
typedef struct binarytree
{
    int data;
    int r;
    int l;
} binarytree;
binarytree nodes[MAXN];
void buildtree(int l, int r, int x)
{
    int flag = -1;
    int i;
    for (i = l; i <= r; i++)
    {
        if (in[i] == pre[t])
        {
            flag = i;
            break;
        }
    }
    if (flag == -1)
    {
        return;
    }
    t++;
    nodes[x].data = in[i];
    nodes[x].l = -1;
    nodes[x].r = -1;

    if (flag > l)
    {
        nodes[x].l = k + 1;
        k++;
        buildtree(l, flag - 1, k);
    }
    if (flag < r)
    {
        nodes[x].r = k + 1;
        k++;
        buildtree(flag + 1, r, k);
    }
}
void postorder(int x)
{
    if (x != -1)
    {
        postorder(nodes[x].l);
        postorder(nodes[x].r);
        post[o++] = nodes[x].data;
    }
}
inline void slove()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pre[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> in[i];
    }
    buildtree(1, n, 0);
    postorder(0);
    for (int i = 1; i < o; i++)
    {
        if (i == o - 1)
        {
            cout << post[i];
            continue;
        }
        cout << post[i] << " ";
    }
    cout << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}
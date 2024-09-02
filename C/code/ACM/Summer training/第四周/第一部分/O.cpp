#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using namespace std;
struct node
{
    int l;
    int w;
} f[5005];
struct node1
{
    bool operator()(const node &s1, const node &s2)
        const
    {
        if (s1.l == s2.l)
        {
            return s1.w > s2.w;
        }
        return s1.l > s2.l;
    }
};
bool fun[5005] = {};
void slove()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i].l >> f[i].w;
    }
    sort(f + 1, f + n + 1, node1());
    for (int i = 1; i <= n; i++)
    {
        if (fun[i] == 0)
        {
            int temp = f[i].w;
            for (int j = i + 1; j <= n; j++)
            {
                if (f[j].w <= temp && fun[j] == 0)
                {
                    fun[j] = 1;
                    temp = f[j].w;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fun[i] == 0)
        {
            sum++;
        }
    }
    cout << sum;
}
int main()
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
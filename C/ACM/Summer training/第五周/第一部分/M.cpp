#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
string mid, aft;
void dfs(int ml, int mr, int al, int ar)
{
    if (ml > mr || al > ar)
    {
        return;
    }
    cout << aft[ar];
    for (int k = ml; k <= mr; k++)
    {
        if (mid[k] == aft[ar])
        {
            dfs(ml, k - 1, al, al + k - ml - 1);
            dfs(k + 1, mr, al + k - ml, ar - 1);
            break;
        }
    }
}
inline void slove()
{
    cin >> mid >> aft;
    int len = mid.length() - 1;
    dfs(0, len, 0, len);
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
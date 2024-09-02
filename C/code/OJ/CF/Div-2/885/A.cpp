#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, m, k;
    int num, ans;
    cin >> n >> m >> k;
    cin >> num >> ans;
    bool flag = true;
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        if ((abs(a - num) + abs(b - ans)) % 2 == 0)
        {
            flag = false;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}
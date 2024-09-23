#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != i)
        {
            flag = false;
        }
    }
    if (flag)
        cout << 0 << endl;
    else
    {
        if (a[1] == 1 || a[n] == n)
        {
            cout << 1 << endl;
        }
        else if (a[n] == 1 && a[1] == n)
        {
            cout << 3 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
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
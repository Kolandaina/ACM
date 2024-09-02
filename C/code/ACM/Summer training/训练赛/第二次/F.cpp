#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int yi = 0, er = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] == 1)
            yi++;
        else
            er++;
    }
    if (er % 2 == 0)
    {
        if (yi % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        if (yi - 2 >= 0 && yi % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
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
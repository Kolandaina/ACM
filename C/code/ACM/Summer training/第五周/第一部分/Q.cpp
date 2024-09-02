#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int build()
{
    int wl, dl, wr, dr;
    cin >> wl >> dl >> wr >> dr;
    if (wl == 0)
        wl = build();
    if (wr == 0)
        wr = build();
    if (wl == 0 || wr == 0 || wl * dl != wr * dr)
        return 0;
    else
        return wl + wr;
}
inline void slove()
{
    int ans = build();
    if (ans)
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
    {
        slove();
        if (t > 0)
            cout << endl;
    }

    return 0;
}
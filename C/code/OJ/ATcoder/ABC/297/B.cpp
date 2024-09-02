#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s;
    cin >> s;
    int b1, b2;
    int k, r1, r2;
    bool flag1 = true, flag2 = true;
    for (int i = 0; i < 8; i++)
    {
        if (s[i] == 'B' && flag1)
        {
            b1 = i;
            flag1 = false;
        }
        if (s[i] == 'B')
            b2 = i;
        if (s[i] == 'K')
            k = i;
        if (s[i] == 'R' && flag2)
        {
            r1 = i;
            flag2 = false;
        }
        if (s[i] == 'R')
            r2 = i;
    }
    if (b1 % 2 != b2 % 2 && r1 < k && k < r2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
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
    {
        slove();
    }
    return 0;
}
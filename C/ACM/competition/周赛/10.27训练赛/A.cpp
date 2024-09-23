#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    string s;
    cin >> n >> s;
    int m = s.size();
    int r = 1;
    int c = 1;
    int firstD = m;
    int firstR = m;
    for (int i = m - 1; i >= 0; i--)
    {
        if (s[i] == 'R')
        {
            ++c;
            firstR = i;
        }
        else
        {
            ++r;
            firstD = i;
        }
    }
    int maxW = n - c + 1;
    int maxH = n - r + 1;
    int ans = maxW * maxH;
    if (firstD == m)
    {
        ans = maxW;
    }
    if (firstR == m)
    {
        ans = maxH;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        if (s[i] == 'D')
        {
            if (firstR < i)
            {
                ans += maxW;
            }
            else
            {
                ans++;
            }
        }
        else
        {
            if (firstD < i)
            {
                ans += maxH;
            }
            else
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
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
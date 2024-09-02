#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s;
    cin >> s;
    int r = 0, g = 0, b = 0, R = 0, G = 0, B = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'R')
            R = i;
        else if (s[i] == 'G')
            G = i;
        else if (s[i] == 'B')
            B = i;
        else if (s[i] == 'r')
            r = i;
        else if (s[i] == 'g')
            g = i;
        else if (s[i] == 'b')
            b = i;
    }
    if (r < R && g < G && b < B)
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
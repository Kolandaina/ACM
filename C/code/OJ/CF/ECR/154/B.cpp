#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    std::string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();
    if (len1 != len2)
    {
        cout << "NO" << endl;
        return;
    }
    if (s1[0] != s2[0] || s1[len1 - 1] != s2[len2 - 1])
    {
        cout << "NO" << endl;
        return;
    }
    bool flag = true;
    for (int i = 0; i < len1; i++)
    {
        if ((s1[i] == '0' && s2[i] == '0') && (s2[i + 1] == '1' && s1[i + 1] == '1'))
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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
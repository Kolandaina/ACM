#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s1, s2;
    cin >> s1 >> s2;
    int ans = 0;
    int len1 = s1.length();
    int len2 = s2.length();
    for (int i = 0; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (s1[i] == s2[j] && s1[i + 1] == s2[j - 1])
            {
                ans++;
            }
        }
    }
    cout << (1 << ans) << endl;
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
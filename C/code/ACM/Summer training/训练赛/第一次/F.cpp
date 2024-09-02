#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, k;
    cin >> n >> k;
    string s;
    for (int i = 0; i < k; i++)
    {
        s.push_back(char('a') + i);
        for (int j = 1; i + j < k; j++)
        {
            s.push_back(char('a') + i);
            s.push_back(char('a') + i + j);
        }
    }
    int cnt = 0;
    int idx = 0;
    while (cnt < n)
    {
        cout << s[idx];
        idx++;
        if (idx == s.size())
            idx = 0;
        cnt++;
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
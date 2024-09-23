#include <bits/stdc++.h>
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
template <class T1>
std::istream &operator>>(std::istream &cin, std::vector<T1> &a)
{
    for (auto &x : a) cin >> x;
    return cin;
}
template <class T1>
std::ostream &operator<<(std::ostream &cout, const std::vector<T1> &a)
{
    int n = a.size();
    if (!n) return cout;
    cout << a[0];
    for (int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout;
}
inline void slove()
{
    std::string s;
    std::cin >> s;
    int n = s.length();
    bool flag = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            if (s[i] == 'a')
            {
                if (s[i + 1] != 'A')
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (s[i] - 32 != s[i + 1] && s[i] - 1 != s[i + 1])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            if (s[i] == 'Z')
            {
                if (s[i + 1] != 'z')
                {
                    flag = false;
                    break;
                }
            }
            else
            {
                if (s[i] + 32 != s[i + 1] && s[i] + 1 != s[i + 1])
                {
                    flag = false;
                    break;
                }
            }
        }
    }
    if (flag)
        std::cout << "Y" << endl;
    else
        std::cout << "N" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}
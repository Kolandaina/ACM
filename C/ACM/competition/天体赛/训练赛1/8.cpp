#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    std::string ch;
    std::getline(std::cin, ch);
    int n;
    std::cin >> n;
    n %= 26;
    if (n > 0) n -= 26;
    int len = ch.length();
    for (int i = 0; i < len; i++)
    {
        if (ch[i] > 64 && ch[i] < 91)
        {
            ch[i] += n;
            if (ch[i] > 90)
            {
                ch[i] -= 26;
            }
            else if (ch[i] < 65)
            {
                ch[i] += 26;
            }
        }
        else if (ch[i] > 96 && ch[i] < 123)
        {
            ch[i] += n;
            if (ch[i] > 122)
            {
                ch[i] -= 26;
            }
            else if (ch[i] < 97)
            {
                ch[i] += 26;
            }
        }
    }
    std::cout << ch << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}
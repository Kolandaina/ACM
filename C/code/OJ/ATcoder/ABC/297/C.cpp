#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string s[110];
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        // getchar();
        cin >> s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (s[i][j] == 'T' && s[i][j - 1] == 'T')
            {
                s[i][j] = 'C';
                s[i][j - 1] = 'P';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
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
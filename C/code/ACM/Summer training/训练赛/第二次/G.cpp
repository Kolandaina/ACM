#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{

    int n;
    string s;
    cin >> n >> s;
    if (n == 2 && s[0] >= s[1])
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl
         << 2 << endl;
    cout << s[0] << " ";
    for (int i = 1; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
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
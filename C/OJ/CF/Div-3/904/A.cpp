#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int op = 0;
    vector<int> a(5);
    string s;
    cin >> s;
    for (int i = 0; i < 4; i++)
    {
        a[i + 1] = s[i] - 49;
        if (a[i] == 0)
            a[i] == 10;
    }
    cout << endl;
    for (int i = 1; i <= 4; i++)
    {
        if (a[i] == 0)
        {
            a[i] = 10;
        }
        op += abs(a[i] - a[i - 1]);
    }
    cout << op + 4 << endl;
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
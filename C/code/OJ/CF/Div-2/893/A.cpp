#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2 == 0)
    {
        if (a > b)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }
    else
    {
        if (a + 1 > b)
        {
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
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
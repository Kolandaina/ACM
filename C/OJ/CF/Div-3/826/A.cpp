#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    string a, b;
    cin >> a >> b;
    if (a.back() == 'S' && b.back() != 'S')
    {
        cout << '<';
    }
    else if (a.back() == 'M' && b.back() == 'L')
    {
        cout << '<';
    }
    else if (a.back() != 'S' && b.back() == 'S')
    {
        cout << '>';
    }
    else if (a.back() == 'L' && b.back() == 'M')
    {
        cout << '>';
    }
    else if (a.back() == 'S')
    {
        if (a.size() < b.size())
            cout << '>';
        else if (a.size() == b.size())
            cout << '=';
        else
            cout << '<';
    }
    else
    {
        if (a.size() > b.size())
            cout << '>';
        else if (a.size() == b.size())
            cout << '=';
        else
            cout << '<';
    }
    cout << '\n';
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
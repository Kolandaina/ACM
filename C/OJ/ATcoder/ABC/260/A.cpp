#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    char a, b, c;
    cin >> a >> b >> c;
    if(a == b&&b == c) cout<< -1 <<endl;
    else
    {
        if(a == b) cout << c << endl;
        else if(a == c) cout << b << endl;
        else if(b == c) cout << a << endl;
        else cout << c << endl;
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
        slove();
    return 0;
}
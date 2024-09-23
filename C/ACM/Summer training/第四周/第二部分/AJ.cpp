#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    std::vector<int> a = {-9, -72, -98, 45, 54, 78, -17, 81, -59};
    std::cout << *std::max_element(a.begin(), a.end()) << endl;
    std::cout << *std::min_element(a.begin(), a.end()) << endl;
    std::cout << std::accumulate(a.begin(), a.end(), INT_MAX) << endl;
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
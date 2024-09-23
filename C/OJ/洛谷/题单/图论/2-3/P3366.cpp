#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
template <typename T>
struct Compare
{
    bool operator()(const T &a, const T &b) const
    {
        return a > b;
    }
};
inline void slove()
{
    std::priority_queue<int, std::vector<int>, Compare<int>> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while (q.size() > 1)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        q.push(x + y);
        ans += (x + y);
    }
    cout << ans << endl;
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
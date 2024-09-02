#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::stacks<int> q;
    std::string ans;
    int l = 1, r = n;
    q.push(0);
    while (l < r)
    {
        if (a[l] > q.top() && a[r] > q.top()) {
            if (a[l] < a[r]) {
                q.push(a[l]);
                l++;
                ans += "L";
            } else {
                q.push(a[r]);
                r--;
                ans += "R";
            }
        } else if (a[l] > q.top()) {
            q.push(a[l]);
            l++;
            ans += "L";
        } else if (a[r] > q.top()) {
            q.push(a[r]);
            r--;
            ans += "R";
        } else {
            break;
        }
    }
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
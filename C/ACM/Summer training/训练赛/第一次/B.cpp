#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    vector<int> a(n + 10), b(n + 10), s(n + 10), ss(n + 10), ans(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        s[i] = s[i - 1] + b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int l = i - 1, r = n;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (s[mid] - s[i - 1] <= a[i])
                l = mid;
            else
                r = mid - 1;
        }
        if (i <= l)
            ss[i]++, ss[l + 1]--;
        ans[l + 1] += a[i] - (s[l] - s[i - 1]);
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += ss[i];
        ans[i] += sum * b[i];
        cout << ans[i] << " ";
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

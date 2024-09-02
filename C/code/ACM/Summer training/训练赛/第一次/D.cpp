#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < n;)
    {
        vector<int> b;
        int j = i;
        while (j < n && s[j] == s[i])
        {
            b.push_back(a[j]);
            // cout << a[j] << " ";
            j++;
        }
        sort(b.begin(), b.end());
        int cnt = 0;
        for (int len = b.size(), i = len - 1; i >= 0; i--)
        {
            if (cnt == k)
                break;
            ans += b[i];
            // cout << b[i] << " ";
            cnt++;
        }
        i = j;
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
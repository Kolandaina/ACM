#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
inline void slove()
{
    int n, a[N];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v;
    v.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            v.push_back(a[i]);
            v.push_back(a[i]);
        }
        else
        {
            v.push_back(a[i]);
        }
    }
    cout << v.size() << endl;
    for (auto e : v)
    {
        cout << e << " ";
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
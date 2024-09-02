#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                ans = a[i];
                break;
            }
            ans = max(ans, a[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
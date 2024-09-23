#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int l = 0, r = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                l++;
                r = 0;
            }
            else
            {
                r++;
                l = 0;
            }
            ans = max(ans, max(r, l));
        }
        cout << ans + 1 << endl;
    }
    return 0;
}
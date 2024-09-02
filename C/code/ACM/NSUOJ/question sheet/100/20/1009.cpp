#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        char m[1000];
        mp.clear();
        int cnt = 0, ans = 0;
        mp[0] = -1;
        for (int i = 0; i < a; i++)
        {
            cin >> m[i];
        }
        for (int i = 0; i < a; i++)
        {
            if (m[i] == '1')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            if (!mp.count(cnt))
            {
                mp[cnt] = i;
            }
            else
            {
                ans = max(ans, i - mp[cnt]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
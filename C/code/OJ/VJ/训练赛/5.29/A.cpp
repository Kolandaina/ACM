#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (s.length() & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        int ans = 1;
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (s[i] != s[i + s.length() / 2])
            {
                ans = 0;
                break;
            }
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
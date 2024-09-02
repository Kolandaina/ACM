#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n >> s;
    string ans;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != s[i - 1])
        {
            ans += s[i - 1];
            ans += s[i];
            i++;
        }
    }
    cout << s.length() - ans.length() << endl
         << ans << endl;
    return 0;
}
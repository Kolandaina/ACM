#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if (n < k * 2 + 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (k == 0)
            {
                cout << "YES" << endl;
            }
            else
            {
                int cnt = 0, ans = 1;
                for (int i = 0, j = n - 1; i < j && cnt < k; i++, j--, cnt++)
                {
                    if (s[i] != s[j])
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
        }
    }
    return 0;
}
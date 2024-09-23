#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        int m = s.length();
        int flag = 0;
        int a[1000];
        memset(a, 0, sizeof(a));
        int min_n = 1000, max_n = 0;
        for (int i = 0; i < m; i++)
        {
            a[s[i]]++;
            min_n = min(min_n, int(s[i]));
            max_n = max(max_n, int(s[i]));
        }
        if (max_n == min_n)
        {
            if (a[min_n] == 1)
            {
                flag = 0;
            }
            else
            {
                flag = 1;
            }
        }
        else
        {
            for (int i = min_n; i < max_n; i++)
            {
                if (a[i] != a[i + 1] || a[i] != 1)
                {
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
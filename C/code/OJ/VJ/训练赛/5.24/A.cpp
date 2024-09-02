#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        string s;
        cin >> a >> s;
        s = " " + s;
        int x = 0, y = 0;
        for (int i = 1; i <= a; i++)
        {
            int n = s[i] - '0';
            if (i & 1)
                if (n % 2 == 1)
                    x++;
                else if (n % 2 == 0)
                    y++;
        }
        if (a % 2 == 0)
            if (y)
                cout << "2" << endl;
            else
                cout << "1" << endl;
        else if (x)
            cout << "1" << endl;
        else
            cout << "2" << endl;
    }
    return 0;
}
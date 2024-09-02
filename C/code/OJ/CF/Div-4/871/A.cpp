#include <bits/stdc++.h>
using namespace std;
const char a[] = {"codeforces"};
string s;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < 11; i++)
        {
            if (a[i] != s[i])
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
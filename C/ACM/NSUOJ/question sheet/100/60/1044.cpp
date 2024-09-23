#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    cout << s;
    int n = s.length();
    for (int i = n; i >= 0; i--)
    {
        cout << s[i];
    }
    return 0;
}
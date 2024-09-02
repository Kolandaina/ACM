#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s1;
        string s2;
        cin >> s1;
        s2 += s1[0];
        s2 += s1[1];
        for (int i = 3; i < s1.length(); i += 2)
        {
            s2 += s1[i];
        }
        cout << s2 << endl;
    }
    return 0;
}
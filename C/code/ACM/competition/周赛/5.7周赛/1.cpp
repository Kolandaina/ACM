#include <bits/stdc++.h>
using namespace std;
int a[27];
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string str;
        cin >> str;
        int m = str.length();
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++)
        {
            a[str[i] - 'a']++;
        }
        cout << m - *max_element(a, a + 27) << endl;
    }
    return 0;
}
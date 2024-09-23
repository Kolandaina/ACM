#include <bits/stdc++.h>
using namespace std;
int a[27];
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        a[int(str[i] - 'a')]++;
    }
    int m = *max_element(a, a + 27);
    for (int i = 0; i < 27; i++)
    {
        if (a[i] == m)
        {
            printf("%c ", i + 'a');
        }
    }
    return 0;
}
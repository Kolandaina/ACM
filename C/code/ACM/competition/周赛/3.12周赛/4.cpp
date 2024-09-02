#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        int n = str.size();
        char B = {'B'};
        char G = {'G'};
        int b = 0, g = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == B)
                b++;
            if (str[i] == G)
                g++;
        }
        if (g < b && str[n - 1] == B)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
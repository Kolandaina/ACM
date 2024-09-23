#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, i, j, c;
    cin >> n;
    while (n--)
    {
        cin >> k;
        int a[k], b[k];
        for (i = 0; i < k; i++)
            cin >> a[i];
        for (i = 0; i < k; i++)
            cin >> b[i];
        int c[101], d[101], e = 0, f = 0;
        for (i = 0; i < k; i++)
        {
            while (a[i] > b[i])
            {
                a[i]--;
                c[e++] = i + 1;
            }
            while (a[i] < b[i])
            {
                a[i]++;
                d[f++] = i + 1;
            }
        }
        if (e == f)
        {
            cout << e << "\n";
            for (i = 0; i < e; i++)
                cout << c[i] << " " << d[i] << "\n";
        }
        else
            cout << "-1\n";
    }
}
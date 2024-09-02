#include <bits/stdc++.h>
using namespace std;
int a[2023];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int m = max_element(a, a + n) - a;
        if (m == 0)
        {
            m = max_element(a + 1, a + n) - a;
        }
        int l = m - 1;
        if (m == n - 1 && a[l] < a[0])
            l = m;
        else
        {
            while (l > 0 && a[l - 1] > a[0])
                l--;
        }
        reverse(a + l, a + m);
        rotate(a, a + l, a + m);
        rotate(a, a + m, a + n);
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
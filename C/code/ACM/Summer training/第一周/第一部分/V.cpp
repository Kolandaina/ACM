#include <bits/stdc++.h>
using namespace std;
int n, a1, a2, a3, b1, b2, b3;
int main()
{
    cin >> n;
    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3;
    int c1 = 0, c2 = 0, c3 = 0;
    int d1 = 0, d2 = 0, d3 = 0;
    while (c1 < n)
    {
        c1 += a1;
        d1 += b1;
    }
    while (c2 < n)
    {
        c2 += a2;
        d2 += b2;
    }
    while (c3 < n)
    {
        c3 += a3;
        d3 += b3;
    }
    cout << min(d1, min(d2, d3)) << endl;
    return 0;
}
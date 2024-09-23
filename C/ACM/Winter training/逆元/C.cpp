#include <iostream>
using namespace std;
#define int long long
int n, m;
int a[1000];
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
signed main()
{
    cin >> n;
    while (n--)
    {
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 0; i < m - 1; i++)
        {
            a[i + 1] = a[i] * a[i + 1] / gcd(a[i + 1], a[i]);
        }
        cout << a[m - 1] << endl;
    }
    return 0;
}
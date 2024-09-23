#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, a[N], b[N];
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    for (int i = 1; i < n; i++)
    {
        b[i] += b[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += a[i] * (i + 1) - b[i];
    }
    cout << abs(ans) << endl;
    return 0;
}

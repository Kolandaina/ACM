#include <iostream>
using namespace std;
const int N = 1e6;
const int m = -1e7;
int a[N], dp[N];
int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        int sum = 0, num = m;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            num = max(sum, num);
            dp[i] = num;
            if (sum < 0)
                sum = 0;
        }
        sum = 0, num = m, dp[0] = m;
        int ans = m;
        for (int i = n; i > 0; i--)
        {
            sum += a[i];
            num = max(sum, num);
            ans = max(ans, num + dp[i - 1]);
            if (sum < 0)
                sum = 0;
        }
        cout << ans << endl;
    }
    return 0;
}
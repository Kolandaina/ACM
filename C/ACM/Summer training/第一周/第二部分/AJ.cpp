#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int dp[N];
int a[N];
bool fun[N][N];
int main()
{
    int m;
    while (cin >> m && m != 0)
    {
        int n;
        cin >> n;
        memset(fun, false, sizeof(fun));
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m; j >= a[i]; j--)
            {
                if (dp[j] <= dp[j - a[i]] + a[i])
                {
                    dp[j] = dp[j - a[i]] + a[i];
                    fun[i][j] = true;
                }
            }
        }
        for (int i = 0, j = m; i < n; i++)
        {
            if (fun[i][j])
            {
                cout << a[i] << " ";
                j -= a[i];
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}
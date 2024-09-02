#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        int arr[N], m = 0;
        string s;
        cin >> n >> k >> s;
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                arr[m++] = i;
            }
        }
        if (m == 0)
            cout << 1 + (n - 1) / (k + 1) << endl;
        else
        {
            int sum = 0;
            if (arr[0] != 0 && arr[0] >= k + 1)
            {
                sum = sum + 1 + (arr[0] - k - 1) / (k + 1);
            }
            for (int i = 1; i < m; i++)
            {
                sum = sum + (arr[i] - arr[i - 1] - k - 1) / (k + 1);
            }
            sum = sum + (n - 1 - arr[m - 1]) / (k + 1);
            cout << sum << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
inline void slove()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    if (arr[0] != 1)
    {
        cout << "NO" << endl;
        return;
    }
    int sum = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > sum)
        {
            cout << "NO" << endl;
            return;
        }
        sum += arr[i];
    }
    cout << "YES" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}
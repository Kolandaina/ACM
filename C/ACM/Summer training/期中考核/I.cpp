#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int a[48] = {
    0,
    1,
    2,
    3,
    4,
    5,
    6,
    7,
    8,
    9,
    19,
    29,
    39,
    49,
    59,
    69,
    79,
    89,
    189,
    289,
    389,
    489,
    589,
    689,
    789,
    1789,
    2789,
    3789,
    4789,
    5789,
    6789,
    16789,
    26789,
    36789,
    46789,
    56789,
    156789,
    256789,
    356789,
    456789,
    1456789,
    2456789,
    3456789,
    13456789,
    23456789,
    123456789,
};
inline void slove()
{
    int n;
    cin >> n;
    cout << a[n] << endl;
}
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}
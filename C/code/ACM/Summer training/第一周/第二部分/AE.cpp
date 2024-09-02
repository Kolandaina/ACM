// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5;
// int a[N], b[N];
// int n;
// double ans;
// void slove()
// {
//     cin >> n;
//     ans = 0;
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     for (int i = 0; i < n; i++)
//         cin >> b[i];
//     int maxn = INT_MIN, minn = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         minn = min(minn, a[i] - b[i]);
//         maxn = max(maxn, a[i] + b[i]);
//     }
//     // cout << minn << " " << maxn << endl;
//     ans = (maxn * 1.0 + minn * 1.0) / 2;
//     printf("%.6f\n", ans);
// }
// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         slove();
//     }
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
double a[N], b[N];
int esp = 1e-6;
int n;
double ans;
bool judge(double x)
{
    double l = -1e18, r = 1e18;
    for (int i = 1; i <= n; i++)
    {
        if (x <= b[i])
        {
            return false;
        }
        else
        {
            double y = x;
            y -= b[i];
            double L = a[i] - y, R = a[i] + y;
            if (r < L || l > R)
                return false;
            l = max(l, L);
            r = min(r, R);
            if (l - esp > r)
            {
                return false;
            }
        }
    }
    ans = l;
    return true;
}
void slove()
{
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    double l = 0.0, r = 1e9;
    while (l + esp < r)
    {
        double mid = (l + r) / 2;
        if (judge(mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    printf("%.10f\n", ans);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}
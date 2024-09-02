#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int n;
int a[N];
void slove()
{

    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = 0;
        a[i] = a[i - 1] + x;
    }
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) / 2;
        cout << "? " << mid - l + 1;
        for (int i = l; i <= mid; i++)
        {
            cout << " " << i;
        }
        cout << endl;
        fflush(stdout);
        int res;
        cin >> res;
        if (a[mid] - a[l - 1] != res)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << "! " << r << endl;
    fflush(stdout);
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
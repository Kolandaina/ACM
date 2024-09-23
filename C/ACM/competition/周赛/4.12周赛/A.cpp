#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
struct node
{
    int a;
    int b;
};
node f[N];
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int sum = 1;
        while (true)
        {
            if (x & 1 == 1)
                break;
            x >>= 1;
            sum++;
        }
        if (f[sum].a == 0)
        {
            f[sum].a = i;
        }
        f[sum].b++;
    }
    for (int i = N; i >= 0; i--)
    {
        if (f[i].a != 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = N; i >= 0; i--)
    {
        if (f[i].a != 0)
        {
            cout << f[i].a << " " << f[i].b << endl;
        }
    }
    return 0;
}
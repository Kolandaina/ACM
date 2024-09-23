#include <iostream>
using namespace std;
int main()
{
    int n, maxx = 0;
    int a[1010];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        maxx = max(a[i], maxx);
    }
    int gcd = 0, ans;
    for (int i = 2; i <= maxx; i++)
    {
        int tot = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] % i == 0)
            {
                tot++;
            }
        }
        if (tot > gcd)
        {
            gcd = tot;
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}

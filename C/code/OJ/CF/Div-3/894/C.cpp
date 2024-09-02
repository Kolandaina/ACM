#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
int a[N];
inline void slove()
{

    int n;
    bool flag = true;
    int ans;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (a[0] != n)
        flag = false;
    else
    {
        ans = n;
        for (int i = 1; i <= n / 2; i++)
        {
            for (int j = ans - 1; j >= 0; j--)
            {
                if (a[j] <= i)
                    ans--;
                else
                    break;
            }
            if (ans != a[i])
                flag = false;
        }
    }
    if (flag)
        printf("YES\n");
    else
        printf("NO\n");
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
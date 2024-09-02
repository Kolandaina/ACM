#include <iostream>
#include <map>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

int ans = 1;
void div(map<int, int> &mp, int n)
{
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n /= i;
            }
        }
    }
    if (n > 1)
    {
        mp[n]++;
    }
}
signed main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 2; i <= n; i++)
    {
        div(mp, i);
    }
    for (auto ietr = mp.begin(); ietr != mp.end(); ietr++)
    {
        ans *= ietr->second + 1;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

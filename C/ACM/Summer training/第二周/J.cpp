#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
int pow(int a, int b, int mod)
{
    int ans = 1;
    int base = a % mod;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * base % mod;
        }
        base = base * base % mod;
        b >>= 1;
    }
    return ans;
}
signed main()
{

    cin >> n >> m;
    cout << pow(10, n, m * m) / m % m << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, mod, p, m;
int phi(int a)
{
    int ans = a;
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            ans = ans / i * (i - 1);
            while (a % i == 0)
                a /= i;
        }
    }
    if (a > 1)
        ans = ans / a * (a - 1);
    return ans;
}
int readint(int j)
{
    int frog = 1, x = 0;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            frog = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = ((x << 3) + (x << 1) + c - '0') % j;
        c = getchar();
    }
    return x * frog == 0 ? j : x * frog;
}

int power(int a, int b, int j)
{
    int ans = 1, base = a % j;
    while (b)
    {
        if (b & 1)
            ans = ans * base % j;
        base = base * base % j;
        b >>= 1;
    }
    return ans;
}

signed main()
{
    cin >> n >> mod;
    n %= mod;
    p = phi(mod);
    m = readint(p);
    if (m <= p)
        cout << power(n, m, mod) << endl;
    else
        cout << power(n, m + p, mod) << endl;
}
#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 20010;
int prime[maxn];
void isPrime()
{
    prime[1] = 1; // 特殊 筛法素数的改版
    for (int i = 2; i < maxn; i++)
    {
        if (prime[i] == 0)
        {
            prime[i] = i;
            for (int j = i + i; j < maxn; j += i)
                prime[j] = i; // 特殊
        }
    }
}
int main()
{
    isPrime();
    int t, n, ans;
    while (cin >> t)
    {
        int max = 0;
        for (int i = 0; i < t; i++)
        {
            cin >> n;
            if (prime[n] > max)
            {
                max = prime[n];
                ans = n;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

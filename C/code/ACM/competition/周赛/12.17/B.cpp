#include <bits/stdc++.h>
#define int long long
#define endl "\n"
int n;
const int N = 1e6 + 10;
std::vector<int> a(N);
bool istrue(int k)
{
    int summ = 0, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (summ + a[i] < k)
        {
            summ += a[i];
        }
        else if (summ + a[i] == k)
        {
            summ = 0;
        }
        else
        {
            return false;
        }
    }
    if (summ != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
inline void slove()
{

    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    int sum = std::accumulate(a.begin() + 1, a.begin() + 1 + n, 0);
    if (sum == 0)
    {
        std::cout << 0 << endl;
        return;
    }
    int minn = 1e9;
    for (int i = 1; i * i <= sum; i++)
    {
        if (sum % i == 0)
        {
            if (istrue(i))
            {
                if (n - sum / i >= 0)
                {
                    minn = std::min(minn, n - sum / i);
                }
            }
            if (istrue(sum / i))
            {
                if (n - i >= 0)
                {
                    minn = std::min(minn, n - i);
                }
            }
        }
    }
    if (minn == 1e9)
    {
        minn = n - 1;
    }
    std::cout << minn << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--)
        slove();
    return 0;
}
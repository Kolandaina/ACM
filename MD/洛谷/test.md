# 题目描述

给定一个数组a，长度为n，下标从1到n；

定义
$$
f(x,y)=\begin{cases} \min(a_x,a_y) \times (x + y) &x \ne y \\ a_x\times x&x=y \end{cases}
$$
对于x,y∈[1,n],求$f(x,y)$的最大值。

# 输入描述

第一行输入数组的长度n；

第二行输入n个元素，第$i$个元素为$a_i$。

# 输出描述

输出一个整数，表示$f(x,y)$的最大值。

# 题解

```c++
#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
inline void solve()
{
    int n;
    std::cin >> n;
    int ans = 0;
    std::vector<std::pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].first;
        a[i].second = i;
        ans = std::max(ans, a[i].first * a[i].second);
    }
    std::sort(a.begin() + 1, a.begin() + n + 1,
              [](auto x, auto y) { return x.first > y.first; });
    int temp = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = std::max(ans, (temp + a[i].second) * a[i].first);
        temp = std::max(temp, a[i].second);
    }
    std::cout << ans << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std::cin >> t;
    while (t--) solve();
    return 0;
}
```


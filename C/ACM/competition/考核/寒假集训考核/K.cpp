#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#define ll long long
#define pcl std::pair<char, long long>
#define IOS ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)
#define endl "\n"
const int mod = 1e9 + 7;
ll t, n, m, p;
void solve()
{
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }
    int x = 1, y = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            x++;
            // std::cout<<x<<endl;
        }
        else
        {
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > a[i + 1])
        {
            y++;
            // std::cout<<y<<endl;
        }
        else
        {
            break;
        }
    }
    if ((x % 2 == 0 && y % 2 == 0))
    {
        std::cout << "ytz" << endl;
    }
    else
    {
        std::cout << "cx" << endl;
    }
}
int main()
{
    std::IOS;
    std::cin >> t;
    while (t--)
    {
        solve();
    }
}
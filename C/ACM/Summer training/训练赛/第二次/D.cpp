#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{

    std::map<int, int> vis;
    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int, char>> p(n);
    std::vector<int> x(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> x[i];
        vis[x[i]] = -1;
        p[i].first = x[i];
    }
    for (int i = 0; i < n; i++)
    {
        std::cin >> p[i].second;
    }
    std::sort(p.begin(), p.end());
    std::stack<std::pair<int, char>> st1, st2;
    for (int i = 0; i < n; i++)
    {
        if (p[i].first % 2)
        {
            if ((!st1.empty()) && p[i].second == 'L')
            {
                auto it = st1.top();
                st1.pop();
                if (it.second == 'R')
                    vis[p[i].first] = vis[it.first] = (p[i].first -
                                                       it.first) /
                                                      2;
                else
                    vis[p[i].first] = vis[-it.first] = (p[i].first -
                                                        it.first) /
                                                       2;
            }
            else if (p[i].second == 'L')
            {
                st1.emplace(-p[i].first, p[i].second);
            }
            else if (p[i].second == 'R')
            {
                st1.emplace(p[i].first, p[i].second);
            }
        }
        else
        {
            if ((!st2.empty()) && p[i].second == 'L')
            {
                auto it = st2.top();
                st2.pop();
                if (it.second == 'R')
                    vis[p[i].first] = vis[it.first] = (p[i].first -
                                                       it.first) /
                                                      2;
                else
                    vis[p[i].first] = vis[-it.first] = (p[i].first -
                                                        it.first) /
                                                       2;
            }
            else if (p[i].second == 'L')
            {
                st2.emplace(-p[i].first, p[i].second);
            }
            else if (p[i].second == 'R')
            {
                st2.emplace(p[i].first, p[i].second);
            }
        }
    }
    while (st1.size() > 1)
    {
        auto it1 = st1.top();
        st1.pop();
        auto it2 = st1.top();
        st1.pop();
        int sum = (m - it1.first + m - it2.first) / 2;
        if (it1.second == 'L')
            vis[-it1.first] = sum;
        else
            vis[it1.first] = sum;
        if (it2.second == 'L')
            vis[-it2.first] = sum;
        else
            vis[it2.first] = sum;
    }
    while (st2.size() > 1)
    {
        auto it1 = st2.top();
        st2.pop();
        auto it2 = st2.top();
        st2.pop();
        int sum = (m - it1.first + m - it2.first) / 2;
        if (it1.second == 'L')
            vis[-it1.first] = sum;
        else
            vis[it1.first] = sum;
        if (it2.second == 'L')
            vis[-it2.first] = sum;
        else
            vis[it2.first] = sum;
    }
    for (auto i : x)
    {
        std::cout << vis[i] << ' ';
    }
    std::cout << '\n';
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
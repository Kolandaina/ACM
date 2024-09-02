#include <bits/stdc++.h>

#define int long long
const int inf = 1e13;

int n{};
std::set<int> p;
std::multiset<int> k;

void modify(int x)
{
    if (x == 0 || x == n) return;
    auto it = p.find(x);
    if (it != p.end())
    {
        int a = *prev(it), b = *next(it);
        k.erase(k.find(x - a)), k.erase(k.find(b - x));
        k.insert(b - a);
        p.erase(it);
    }
    else
    {
        it = p.insert(x).first;
        int a = *prev(it), b = *next(it);
        k.erase(k.find(b - a));
        k.insert(x - a), k.insert(b - x);
    }
}

void solved()
{
    std::string s;
    std::cin >> s;
    n = (int)s.size();
    p.insert(0);
    p.insert(n);

    for (int i = 1; i < n; i++)
        if (s[i] != s[i - 1]) p.insert(i);

    for (auto it = p.begin(); next(it) != p.end(); it++)
    {
        k.insert(*next(it) - *it);
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x;
        std::cin >> x;
        modify(x - 1);
        modify(x);
        std::cout << *k.rbegin() << ' ';
    }
}

// void setIO(std::string name = "") {
//     if (name.size()) {
//         freopen((name + ".in").c_str(), "r", stdin);
//         freopen((name + ".out").c_str(), "w", stdout);
//     }
// }

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // setIO("");

    int t = 1;
    // std::cin >> t;
    for (int i = 0; i < t; ++i) solved();

    return 0;
}
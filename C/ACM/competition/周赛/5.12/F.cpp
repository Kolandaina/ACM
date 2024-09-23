#include <bits/stdc++.h>

#define int long long

void solved()
{
    int n, m;
    std::cin >> n >> m;
    std::string s, t;
    std::cin >> s >> t;

    auto check = [&](int p) -> bool {
        bool ok = false;
        for (int i = 0; i < m; i++)
        {
            if (s[i + p] != t[i] && s[i + p] != '#') return false;
            if (s[i + p] == t[i]) ok = true;
        }
        return ok;
    };

    auto op = [&](int p) -> void {
        for (int i = 0; i < m; i++) s[i + p] = '#';
    };

    std::queue<int> q;
    for (int i = 0; i < n - m + 1; i++)
    {
        if (check(i))
        {
            op(i);
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        for (int i = std::max(0ll, p - m + 1); i < std::min(n - m + 1, p + m);
             i++)
        {
            if (check(i))
            {
                op(i);
                q.push(i);
            }
        }
    }
    // std::cout << s;

    bool k = true;
    for (auto i : s)
    {
        if (i != '#')
        {
            k = false;
            break;
        }
    }

    std::cout << (k ? "Yes" : "No");
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    solved();

    return 0;
}

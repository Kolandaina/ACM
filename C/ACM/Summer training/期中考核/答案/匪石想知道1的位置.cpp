#include <bits/stdc++.h>

#define int long long

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);

    struct segmentTree
    {
        struct node
        {
            int l, r;
            int sum, la;
        };

        segmentTree(int n)
        {
            t = std::vector<node>(n + 1 << 2);
            a = std::vector<int>(n + 1);
            for (int i = 1; i <= n; i++)
            {
                std::cin >> a[i];
            }
            build(1, 1, n);
        }

        void build(int p, int l, int r)
        {
            t[p].l = l, t[p].r = r;
            if (l == r)
            {
                t[p].sum = a[l];
                return;
            }
            int mid = l + r >> 1;
            build(p * 2, l, mid);
            build(p * 2 + 1, mid + 1, r);
            t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
        }

        void change(int p, int x)
        {
            if (t[p].l == t[p].r)
            {
                t[p].sum ^= 1;
                return;
            }
            int mid = t[p].l + t[p].r >> 1;
            if (x <= mid)
                change(p * 2, x);
            else
                change(p * 2 + 1, x);
            t[p].sum = t[p * 2].sum + t[p * 2 + 1].sum;
        }

        int ask(int p, int l, int r)
        {
            if (l <= t[p].l && r >= t[p].r)
            {
                return t[p].sum;
            }
            int mid = t[p].l + t[p].r >> 1;
            int val = 0;
            if (l <= mid)
                val += ask(p * 2, l, r);
            if (r > mid)
                val += ask(p * 2 + 1, l, r);
            return val;
        }

    private:
        std::vector<node> t;
        std::vector<int> a;
    };

    int n, m;
    std::cin >> n >> m;

    segmentTree seg(n);

    int op, k;
    for (int i = 0; i < m; i++)
    {
        std::cin >> op >> k;
        if (op == 1)
        {
            seg.change(1, k + 1);
        }
        else
        {
            int l = 0, r = n + 1;
            while (l + 1 < r)
            {
                int mid = l + r >> 1;
                if (seg.ask(1, 1, mid) >= k + 1)
                    r = mid;
                else
                    l = mid;
            }
            std::cout << r - 1 << '\n';
        }
    }

    return 0;
}

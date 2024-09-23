#include <bits/stdc++.h>

void solved()
{
    struct segmentTree
    {
        struct node
        {
            int l, r, l1, r1;
            int add;
            bool tag;
        };

        void pushup(node &root, node &treel, node &treer)
        {
            root.tag = treel.tag | treer.tag;

            if (treel.r1 == treer.l1)
                root.tag = true;
            root.l1 = treel.l1, root.r1 = treer.r1;
        }

        void pushup(int p)
        {
            pushup(t[p], t[p * 2], t[p * 2 + 1]);
        }

        segmentTree(int n)
        {
            t = std::vector<node>((n + 1) << 2);
            a = std::vector<int>(n + 1);

            for (int i = 1; i <= n; i++)
            {
                std::cin >> a[i];
            }

            build(1, 1, n);
        }

        void build(int p, int l, int r)
        {
            t[p] = {l, r, a[l], a[r], 0, false};
            if (l == r)
                return;
            int mid = (l + r) >> 1;
            build(p * 2, l, mid);
            build(p * 2 + 1, mid + 1, r);
            pushup(p);
        }

        void change(int p, int d)
        {
            t[p].l1 = (t[p].l1 + d) % 100;
            t[p].r1 = (t[p].r1 + d) % 100;
            t[p].add = (t[p].add + d) % 100;
        }

        void spread(int p)
        {
            if (t[p].add)
            {
                change(p * 2, t[p].add);
                change(p * 2 + 1, t[p].add);
            }
            t[p].add = 0;
        }

        void modify(int p, int l, int r, int d)
        {
            if (l <= t[p].l && r >= t[p].r)
            {
                change(p, d);
                return;
            }
            spread(p);
            int mid = (t[p].l + t[p].r) >> 1;
            if (l <= mid)
                modify(p * 2, l, r, d);
            if (r > mid)
                modify(p * 2 + 1, l, r, d);
            pushup(p);
        }

        node ask(int p, int l, int r)
        {
            if (l <= t[p].l && r >= t[p].r)
            {
                return t[p];
            }
            spread(p);
            int mid = (t[p].l + t[p].r) >> 1;

            node left, right, res;

            if (l <= mid)
                left = ask(p * 2, l, r);
            if (r > mid)
                right = ask(p * 2 + 1, l, r);

            if (l <= mid && r <= mid)
                return left;
            if (l > mid && r > mid)
                return right;
            pushup(res, left, right);
            return res;
        }

    private:
        std::vector<node> t;
        std::vector<int> a;
    };

    int n, m;
    std::cin >> n >> m;

    segmentTree seg(n);

    for (int i = 0; i < m; i++)
    {
        int op, l, r, x;
        std::cin >> op >> l >> r;
        if (op == 1)
        {
            std::cin >> x;
            x %= 100;
            seg.modify(1, l, r, x);
        }
        else if (op == 2)
        {
            if (seg.ask(1, l, r).tag)
                std::cout << "YES\n";
            else
                std::cout << "NO\n";
        }
    }
}

int main()
{
    int t = 1;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
        solved();

    return 0;
}
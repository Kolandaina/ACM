#include <bits/stdc++.h>
using ll = long long;
int main()
{
    ll n, m;
    std::cin >> n >> m;
    std::vector<ll> a(n + 1), d(m + 1), s(m + 1), t(m + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        std::cin >> d[i] >> s[i] >> t[i];
    }
    ll l = -1, r = m + 1;
    auto check = [&] (int mid) {
        std::vector<int> b(n + 1);
        for (int i = 1; i <= mid; i++) { //差分的实现
            b[s[i]] += d[i];
            b[t[i] + 1] -= d[i];
        }
        ll sum = 0;
        for (int i = 1; i <= n; i++) { // 计算到i的差分数组的前缀和，如果a[i] < sum ,就代表厨房不够了
            sum += b[i];
            if (a[i] < sum) {
                return 0;
            }
        }
        return 1;
    };
    if (check(m))    {
        std::cout << "0" << '\n';
        return 0;
    }
    while (r - l > 1) { //闭区间二分
        ll mid = (r + l) >> 1;
        if (check(mid)) { //如果返回1，代表该位置的订单是合法的，可以继续向后走
            l = mid;
        }
        else {
            r = mid;
        }
    }
    std::cout << "-1" << '\n' << r << '\n';
    return 0;
}

//线段树版本

//#include <bits/stdc++.h>
//
//int main()
//{
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(0), std::cout.tie(0);
//
//    struct segmentTree
//    {
//        struct node
//        {
//            int l, r;
//            int min1, add;
//        };
//
//        segmentTree(int n)
//        {
//            t = std::vector<node>(n + 1 << 2);
//            a = std::vector<int> (n + 1);
//            for(int i = 1; i <= n; i++)
//                std::cin >> a[i];
//            build(1, 1, n);
//        }
//
//        void build(int p, int l, int r)
//        {
//            t[p].l = l, t[p].r = r, t[p].min1 = 0x3f3f3f3f;
//            if(l == r)
//            {
//                t[p].min1 = a[l];
//                return ;
//            }
//            int mid = l + r >> 1;
//            build(p * 2, l, mid);
//            build(p * 2 + 1, mid + 1, r);
//            t[p].min1 = std::min(t[p * 2].min1, t[p * 2 + 1].min1);
//        }
//
//        void spread(int p)
//        {
//            if(t[p].add)
//            {
//                t[p * 2].min1 -= t[p].add;
//                t[p * 2 + 1].min1 -= t[p].add;
//
//                t[p * 2].add += t[p].add;
//                t[p * 2 + 1].add += t[p].add;
//
//                t[p].add = 0;
//            }
//        }
//
//        void change(int p, int l, int r, int d)
//        {
//            if(l <= t[p].l && r >= t[p].r)
//            {
//                t[p].min1 -= d;
//                t[p].add += d;
//                return ;
//            }
//            spread(p);
//            int mid = t[p].l + t[p].r >> 1;
//            if(l <= mid)
//                change(p * 2, l, r, d);
//            if(r > mid)
//                change(p * 2 + 1, l, r, d);
//            t[p].min1 = std::min(t[p * 2].min1, t[p * 2 + 1].min1);
//        }
//
//        int ask(int p, int l, int r)
//        {
//            if(l <= t[p].l && r >= t[p].r)
//            {
//                return t[p].min1;
//            }
//            spread(p);
//            int mid = t[p].l + t[p].r >> 1;
//            int val = 0x3f3f3f3f;
//            if(l <= mid)
//                val = std::min(val, ask(p * 2, l, r));
//            if(r > mid)
//                val = std::min(val, ask(p * 2 + 1, l, r));
//            return val;
//        }
//
//    private:
//        std::vector<node> t;
//        std::vector<int> a;
//    };
//
//    int n, m;
//    std::cin >> n >> m;
//
//    segmentTree seg(n);
//    int res = 0;
//
//    for(int i = 0; i < m; i++)
//    {
//        int d, l, r;
//        std::cin >> d >> l >> r;
//        if(d <= seg.ask(1, l, r))
//        {
//            seg.change(1, l, r, d);
//        }
//        else 
//        {
//            std::cout << "-1\n";
//            std::cout << i + 1;
//            return 0;
//        }
//    }
//
//    std::cout << 0;
//
//    return 0;
//} 

#include<bits/stdc++.h>

#define int long long
using namespace std;
int n, m, k, yun[55], fang[55];

signed main() {
    cin >> n >> m >> k;
    if (m <= 3) {
        puts("-1");
        return 0;
    }
    if (n == 1) {
        if (m >= k + 3) {
            printf("{1}");
            for (int i = 1; i <= k; ++i)printf(",");
            puts("");
        } else puts("-1");
        return 0;
    }
    for (int i = 1; i <= n + 1; ++i) {
        int now = (1 << (i - 1));
        int g = 0;
        while (now)now /= 10, g++;
        yun[i] = m;
        yun[i] -= g;
        yun[i] -= 2;
    }
    if (k == 1) {
        if (yun[n + 1] < 2) {
            puts("-1");
            return 0;
        }
        for (int i = 2; i <= n + 1; ++i) {
            fang[i] = 1;
            if (i == n + 1)fang[i]++;
            int now = (1 << (i - 1));
            printf("{%d}", now);
            for (int j = 1; j <= fang[i]; ++j)printf(",");
            puts("");
        }
        return 0;
    }
    if (yun[n] < 2) {
        puts("-1");
        return 0;
    }
    yun[1]--;
    fang[1]++;
    k--;
    for (int i = n; i >= 2; --i) {
        while (yun[i] >= 2 && k > 0) {
            k--;
            yun[i] -= 2;
            fang[i] += 2;
            for (int j = i - 1; j >= 2; --j)yun[j]--, fang[j]++;;
        }
    }
    while (k > 0 && yun[1] >= 1)yun[1]--, fang[1]++, k--;
    if (k) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= n; ++i) {
        int now = (1 << (i - 1));
        printf("{%d}", now);
        for (int j = 1; j <= fang[i]; ++j)printf(",");
        puts("");
    }
}

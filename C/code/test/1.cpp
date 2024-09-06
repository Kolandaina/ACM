#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p = 2e5 + 10, mod = 1e9 + 7;

int n;
map<pair<int, int>, int>mp1;
struct node {
    int x, y;
} a[p];
bool cmp(node a, node b) {
    if (a.x == b.x)return a.y < b.y;
    return a.x < b.x;
}

signed main() {
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (1 << n); i++) {
        int x = 0, y = 0;
        map<pair<int, int>, int>mp;
        int f = 0;
        mp[ {0, 0}] = 1;
        for (int j = 0; j < n; j++) {
            int dx = 0, dy = 0;
            if (s[j] == 'L')dx = -1;
            else if (s[j] == 'R')dx = 1;
            else if (s[j] == 'U')dy = 1;
            else if (s[j] == 'D')dy = -1;
            if (i & (1 << j)) {
                x += dx, y += dy;
                mp[ {x, y}] = 1;
            } else {
                if (mp[ {x + dx, y + dy}]) {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0 && mp1[ {x, y}] == 0) {
            a[++cnt].x = x;
            a[cnt].y = y;
            mp1[ {x, y}] = 1;
        }
    }
    printf("%lld\n", cnt);
    sort(a + 1, a + 1 + cnt, cmp);
    for (int i = 1; i <= cnt; i++) {
        printf("%lld %lld\n", a[i].x, a[i].y);
    }
}
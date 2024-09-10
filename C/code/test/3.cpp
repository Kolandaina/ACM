#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define int long long

const int p = 3e7 + 10;
char a[p], s[p];
int d[p];
signed main() {
    scanf("%s", a + 1);
    int n = strlen(a + 1), k = 0;
    s[0] = '$', s[++k] = '#';
    for (int i = 1; i <= n; i++) {
        s[++k] = a[i], s[++k] = '#';
    }
    n = k;
    d[1] = 1;
    for (int i = 2, l, r = 1; i <= n; i++) {
        if (i <= r)d[i] = min(d[r - i + l], r - i + 1);//边界值
        while (s[i - d[i]] == s[i + d[i]])d[i]++;//回文半径
        if (i + d[i] - 1 > r)l = i - d[i] + 1, r = i + d[i] - 1;//回文盒子扩展
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(d[i], ans);
    }
    cout << ans - 1 << endl;
}
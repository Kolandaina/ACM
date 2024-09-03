#include<bits/stdc++.h>
using namespace std;
int n, t, sum, b[10005], a[10005];
int main() {
    scanf("%d", &t);
    while (t--) {
        sum = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), sum += a[i], b[i] = a[i] % i;
        if (sum % n != 0) {
            printf("-1\n");
            continue;
        }
        printf("%d\n", 3 * (n - 1));
        for (int i = 2; i <= n; i++) {
            printf("1 %d %d\n", i, (i - b[i]) % i);
            if (a[i] % i != 0) {
                a[1] = a[1] - ((i - b[i]) % i);
                a[i] = a[i] + ((i - b[i]) % i);
            }
            printf("%d 1 %d\n", i, a[i] / i);
            a[1] = a[1] + a[i];
            a[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            printf("1 %d %d\n", i, sum / n);
            a[1] -= sum / n;
            a[i] = sum / n;
        }
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
int f[N];

int main()
{
    f[0] = 0;
    for (int i = 1; i <= 1000000; i++)
        if (i & 1) f[i] = !f[i - 1];
        else f[i] = !(f[i - 1] && f[i >> 1]);
    int t; scanf("%d", &t);
    while (t--)
    {
        int a; scanf("%d", &a);
        printf("%s\n", f[a] ? "Alice" : "Bob");
    }
    return 0;
}

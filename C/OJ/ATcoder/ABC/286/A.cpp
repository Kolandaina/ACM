#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int n, P, Q, R, S;
int a[110];
int main()
{
    cin >> n >> P >> Q >> R >> S;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= Q - P; i++)
        swap(a[i + P], a[i + R]);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}
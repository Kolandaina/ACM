#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int a[N][N];
int b[N][N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = a[i - 1][j] + a[i][j - 1] + a[i][j];
        }
    }
}
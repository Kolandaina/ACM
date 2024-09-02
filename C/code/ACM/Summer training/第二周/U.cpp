#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N];
void init()
{
    for (int i = 1; i < N; i++)
    {
        if (double(sqrt(i)) == int(sqrt(i)))
        {
            a[i]++;
        }
        a[i] += a[i - 1];
    }
}
int main()
{
    int l, r;
    init();
    while (cin >> l >> r && (l != 0 || r != 0))
    {
        cout << a[r] - a[l - 1] << endl;
    }
    return 0;
}
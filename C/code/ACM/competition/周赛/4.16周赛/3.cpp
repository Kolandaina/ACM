#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n;
map<int, int> a;
map<int, int> b;
map<int, int> c;
int q, e, w;
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q = max(q, x);
        a[x]++;
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        w = max(w, x);
        b[x]++;
    }
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        e = max(e, x);
        c[x]++;
    }
    long long res = 0;
    for (int j = 0; j < w; ++j)
    {
        int i = 0, k = e;
        int x = 0, y = 0, z = 0;
        while (i < q && a[i] < b[j])
            x += 1;
        while (k >= 0 && c[k] > b[j])
            k--;
        res += (long long)i * (n - k - 1);
    }
    cout << res << '\n';
    return 0;
}

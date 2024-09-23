#include <bits/stdc++.h>
using namespace std;
int n, k, b;
int main()
{

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        b = max(b, y - k * x);
    }
    cout << b << endl;
}
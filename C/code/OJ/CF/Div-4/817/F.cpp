#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n % 4 == 2)
    {
        for (int i = 0; i < n - n % 4 - 4; ++i)
        {
            cout << 16 + i << ' ';
        }
        cout << "0 1 5 7 12 15";
    }
    else
    {
        for (int i = 0; i < n - n % 4; ++i)
        {
            cout << 4 + i << ' ';
        }
        if (n % 4 == 1)
        {
            cout << 0;
        }
        else if (n % 4 == 3)
        {
            cout << "1 2 3";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << '\n';
    }

    return 0;
}

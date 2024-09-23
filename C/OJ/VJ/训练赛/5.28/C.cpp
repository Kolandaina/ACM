#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    map<int, bool> mp;
    int i;
    std::vector<int> vc(n);

    for (i = 0; i < n; i++)
    {
        cin >> vc[i];
        mp[vc[i]] = true;
    }
    sort(vc.begin(), vc.end());
    if (k == 0)
    {
        cout << n << endl;
        return;
    }
    if (vc[n - 1] == n - 1)
    {
        cout << n + k << endl;
        return;
    }
    int mex;
    for (i = 0; i < n; i++)
    {
        if (i != vc[i])
        {
            mex = i;
            break;
        }
    }
    int nw = mex + vc[n - 1];
    if (nw % 2 == 0)
        nw = nw / 2;
    else
        nw = nw / 2 + 1;

    if (mp[nw] == 1)
        cout << n << endl;
    else
        cout << n + 1 << endl;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
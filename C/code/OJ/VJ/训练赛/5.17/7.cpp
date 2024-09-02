#include <bits/stdc++.h>
using namespace std;
int n, x, ans = 1;
map<int, int> mp1;
map<int, int> mp2;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        mp1[x]++;
        mp2[mp1[x]]++;
        if (mp1[x] * mp2[mp1[x]] == i + 1 && i != n - 1)
            ans = i + 2;
        else if (mp1[x] * mp2[mp1[x]] == i)
            ans = i + 1;
    }
    cout << ans << endl;
    return 0;
}
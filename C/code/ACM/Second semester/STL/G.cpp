#include <bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> p;
int n, m, a, b, c, x;
int main()
{
    cin >> n >> m;
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> a >> b >> c;
            p[{a, b}] = c;
        }
        else
        {
            cin >> a >> b;
            cout << p[{a, b}] << endl;
        }
    }
    return 0;
}
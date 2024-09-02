#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
map<string, int> mp;
int p[N];
int find(int x)
{
    if (p[x] != x)
    {
        p[x] = find(p[x]);
    }
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        mp[a] = i;
        p[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        p[find(mp[a])] = find(mp[b]);
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        if (find(mp[a]) == find(mp[b]))
            cout << "Yes." << endl;
        else
            cout << "No." << endl;
    }
    return 0;
}

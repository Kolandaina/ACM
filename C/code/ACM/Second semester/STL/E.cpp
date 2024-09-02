#include <bits/stdc++.h>
using namespace std;
map<int, int> v;
int main()
{
    int n, m;
    cin >> n >> m;
    int ans, vis = 0, a = 1;
    map<int, int>::iterator it;
    for (int i = 0; i < n; i++)
    {
        cin >> ans;
        it = v.find(ans);
        if (it == v.end())
        {
            v[ans] = i;
            vis++;
        }
    }
    if (vis < m)
    {
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        cout << "YES" << endl;
        for (it = v.begin(); it != v.end(); it++)
        {
            cout << it->second + 1 << " ";
            a++;
            if (a == m)
                break;
        }
    }
}
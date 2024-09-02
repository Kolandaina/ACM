#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int n, ans = 1e8;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    while (!m.empty())
    {
        map<int, int>::iterator i = m.begin();
        map<int, int>::iterator j = m.begin();
        i->second--;
        int t = 1;
        for (j++; j != m.end() && j->first == i->first + 1 && j->second > i->second; i++, j++)
        {
            t++;
            j->second--;
        }
        i = m.begin();
        while (i != m.end() && i->second == 0)
            m.erase((i++)->first);
        if (t < ans)
            ans = t;
    }
    printf("%d", ans);
    return 0;
}
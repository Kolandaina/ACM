#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int p[N];
int n, m, q;
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

    cin >> n >> m >> q;
    for (int i = 0;i < n; i++)
    {
		p[i] = i;
	}
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        p[find(x)] = find(y);
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y))
            cout << "Yes"<<endl;
        else
            cout << "No"<<endl;
    }
    return 0;
}

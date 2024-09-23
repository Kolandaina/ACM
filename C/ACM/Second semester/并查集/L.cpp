#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
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
	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}
	while (m--)
	{
		char v;
		int a, b;
		cin >> v >> a >> b;
		if (v == 'F')
		{
			p[find(a)] = find(b);
		}
		else
		{
		}
	}
	return 0;
}
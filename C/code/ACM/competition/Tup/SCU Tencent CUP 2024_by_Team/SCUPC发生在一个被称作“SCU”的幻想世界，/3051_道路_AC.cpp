#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

typedef vector<int> vi;
typedef double db;
typedef pair<int, int> pii;

const int N = 1e6 + 10, inf = 0x3f3f3f3f3f3f3f3f;

int n;
int h[N], ne[N], e[N], idx;
bool vis[N];
int d[N];
pii p[N];
int fa[N];
int du[N];

void add(int a, int b)
{
	e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void dfs(int u, int f)
{
	d[u] = d[f] + 1;
	fa[u] = f;
	for (int i = h[u]; i; i = ne[i])
	{
		int j = e[i];
		if (j == f)
			continue;
		dfs(j, u);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		add(i, x), add(x, i);
//		fa[i] = x;
		du[i]++, du[x]++;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		p[i] = {d[i], i};
	sort(p + 1, p + 1 + n);
	int mncnt = inf, mxcnt = 0;
//	for (int i = 1; i <= n; i++)
//		cout << p[i].first << " " << p[i].second << endl;
	vis[0] = vis[1] = true;
	for (int i = 1; i <= n; i++)
	{
		if (du[p[i].second] > 1 || p[i].second == 1)
			continue;
		int now = p[i].second;
		int cnt = 1;
		vis[now] = true;
		while (!vis[fa[now]])
		{
			cnt++;
			now = fa[now];
			vis[now] = true;
		}
		mxcnt = max(mxcnt, cnt), mncnt = min(mncnt, cnt);
	}
	cout << mxcnt - mncnt << endl;
	return 0;
}

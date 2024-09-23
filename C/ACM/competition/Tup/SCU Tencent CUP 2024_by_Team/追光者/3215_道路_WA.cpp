#include<bits/stdc++.h>
#define inf 1e8
#define int long long
using namespace std;
const int N = 2e5 + 10;
int n, h[N], e[N << 1], ne[2*N], idx, res= 0;

void add(int a,int b)
{
	e[idx]=b, ne[idx]=h[a], h[a]=idx++;
}

bool st[N];
int dfs(int s)
{
	st[s] = true;
	int mi = n, ma = 0;
	
	int cnt = 0;
	for(int i = h[s]; i != -1; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			int t = dfs(j);
			mi = min(mi, t);
			ma = max(ma, t);
			cnt++;
		}
	}
	if(cnt == 0) return 1;
	
//	cout<<s<<' '<<ma<<' '<<mi<<endl;
	if(ma == mi) return ma + 1;
	else
	{
		res = max(res, ma - mi - 1);
		return mi + 1;
	}
}

signed main()
{
	memset(h,-1,sizeof h);
	cin >> n;
	
	for(int i = 1;i <= n - 1; i++)
	{
		int x;
		cin >> x;
		add(x, i + 1), add(i + 1, x);
	}
	
	dfs(1);
	cout << res + 1;
	
	return 0;
}

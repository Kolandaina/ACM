#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int fa[N], cnt[N];
queue<int> q;
int minn[N], vis[N];
int main()
{
	scanf("%d", &n);
//	for(int i = 1;i <= n;i ++) maxn[i] = -1e9;
	for(int i = 2;i <= n;i ++)
		scanf("%d", &fa[i]);
	for(int i = 2;i <= n;i ++)
		cnt[fa[i]] ++;
	for(int i = 1;i <= n;i ++)
		if(!cnt[i]) minn[i] = 1, q.push(i);
	int Minn = 1e9;
	while(!q.empty())
	{
		int o = q.front();
		q.pop();
		int u = fa[o];
		if(!vis[u] && u != 1) 
		{
			minn[u] = minn[o] + 1;
			vis[u] = 1;
			q.push(u);
		}
		else Minn = min(Minn, minn[o]);
	}
	int maxn = 0; 
	for(int i = 1;i <= n;i ++) maxn = max(maxn, minn[i]);
	printf("%d", maxn - Minn);
	return 0;
}
/*
6
1 2 2 4 1
*/

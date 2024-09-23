#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;

const int oo=0x3f3f3f3f;
struct node
{
	int v,next;
}ed[maxn<<1];
int n;
int tot,head[maxn];
int mn,mx,dp[maxn],cnt[maxn];

void add(int x,int y)
{
	tot++;
	ed[tot].v=y;
	ed[tot].next=head[x];
	head[x]=tot;
}

void dfs(int x,int fa)
{
	int mn=oo;
	dp[x]=1;
	for(int t=head[x];t;t=ed[t].next)
	{
		int y=ed[t].v;
		if(y==fa)
		continue;
		dfs(y,x);
		mn=min(mn,dp[y]);
	}
	int fl=0;
	for(int t=head[x];t;t=ed[t].next)
	{
		int y=ed[t].v;
		if(y==fa)
		continue;
		if(dp[y]==mn&&!fl&&x!=1)
		{
			dp[x]=dp[y]+1;
			fl=1;
		}
		else
		cnt[dp[y]]++;
	}
}

int main()
{
	mn=oo;
	scanf("%d",&n);
	if(n==1)
	{
		printf("0");
		return 0;
	}
	for(int i=2;i<=n;++i)
	{
		int x;
		scanf("%d",&x);
		add(x,i);
		add(i,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;++i)
	{
		if(!cnt[i])
		continue;
		mn=min(mn,i);
		mx=max(mx,i);
	}
	printf("%d",mx-mn);
	return 0;
}

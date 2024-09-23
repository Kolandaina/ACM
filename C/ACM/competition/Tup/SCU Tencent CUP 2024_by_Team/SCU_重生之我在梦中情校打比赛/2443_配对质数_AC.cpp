#include<cstdio>
#define maxn 4000005
using namespace std;

const int M=4000000;
int t,n;
int tot,prime[maxn],mark[maxn];

void ready()
{
	for(int i=2;i<=M;++i)
	{
		if(!mark[i])
		prime[++tot]=i;
		for(int j=1;j<=tot;++j)
		{
			int x=i*prime[j];
			if(x>M)
			break;
			mark[x]=1;
			if(i%prime[j]==0)
			break;
		}
	}
}

void solve()
{
	scanf("%d",&n);
	if(n==1)
	{
		printf("1 2\n");
		return;
	}
	n<<=1;
	for(int i=2;i<=tot&&prime[i]<=n;++i)
	{
		if(!mark[n+prime[i]])
		{
			int p=prime[i];
			for(int j=1;j<=p-j;++j)
			printf("%d %d\n",j,p-j);
			for(int j=p;j<=n-(j-p);++j)
			printf("%d %d\n",j,n-(j-p));
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	ready();
	scanf("%d",&t);
	while(t--)
	solve();
	return 0;
}

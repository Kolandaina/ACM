#include <bits/stdc++.h>
#define N 200005
using namespace std;

struct Edge{
	long long next;
	long long u,v;
};

struct Node{
	long long dep;
	long long id;
	long long fa;
	bool operator < (const Node &a) const {
		return dep<a.dep;
	}
};

long long n;
Node a[N];
Edge e[N<<1];
long long head[N];
long long cnt;
long long sum;
long long maxx,minn;
bool Notleaf[N];
bool vis[N];

void add(long long u,long long v)
{
	cnt++;
	e[cnt].	u=u;
	e[cnt].	v=v;
	e[cnt].next =head[u];
	head[u]=cnt;
}

void build(long long u)
{
	for(long long i=head[u];i;i=e[i].next)
	{
		long long v=e[i].v;
		a[v].dep=a[u].dep+1;
		build(v);
	}
}

void up(long long u)
{
	if(u==1||u==0)
		return ;

	if(vis[u]==0)
	{
		sum++;
	}
	vis[u]=1;
	up(a[u].fa);
	return ;
}

Node s[N];
long long cnts;

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	a[1].id=1;
	vis[1]=1;
	for(long long i=2;i<=n;i++)
	{
		a[i].id=i;
		cin>>a[i].fa;
		add(a[i].fa,i);
		Notleaf[a[i].fa]=1;
		//cout<<a[i].fa<<endl;
	}
	build(1);
	for(long long i=1;i<=n;i++)
	{
		if(Notleaf[a[i].id]==0)
		{
			//s.insert(a[i]);
			s[++cnts]=a[i];
		}
	}
	sort(s+1,s+cnts+1);
	/*for(long long i=1;i<=n;i++)
	{
		cout<<i<<" "<<s[i].dep<<" "<<Notleaf[s[i].id]<<endl;	 
	}*/
	
	maxx=0;
	minn=0x7fffffff;

	for(long long i=1;i<=cnts;i++)
	{
		//cout<<s[i].id<<" "<<s[i].dep<<endl;
		sum=0;
		up(s[i].id);
		maxx=max(maxx,sum);
		minn=min(minn,sum);
		//cout<<sum<<endl;
	}
	
	cout<<abs(maxx-minn)<<endl;;
	
	return 0;
	
}

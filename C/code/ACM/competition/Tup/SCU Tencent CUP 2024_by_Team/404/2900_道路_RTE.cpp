#include <bits/stdc++.h>
#define N 20005
using namespace std;

struct Edge{
	int next;
	int u,v;
};

struct Node{
	int dep;
	int id;
	int fa;
	bool operator < (const Node &a) const {
		return dep<a.dep;
	}
};

int n;
Node a[N];
Edge e[N<<1];
int head[N];
int cnt;
int sum;
int maxx,minn;
bool Notleaf[N];
bool vis[N];

void add(int u,int v)
{
	cnt++;
	e[cnt].	u=u;
	e[cnt].	v=v;
	e[cnt].next =head[u];
	head[u]=cnt;
}

void build(int u)
{
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].v;
		a[v].dep=a[u].dep+1;
		build(v);
	}
}

void up(int u)
{
	if(u==1)
		return ;
	if(vis[u]==0)
	{
		sum++;
		vis[u]=1;
	}

	up(a[u].fa);
}

Node s[N];
int cnts;

int main()
{
	//freopen("in.txt","r",stdin);
	cin>>n;
	a[1].id=1;
	for(int i=2;i<=n;i++)
	{
		a[i].id=i;
		cin>>a[i].fa;
		add(a[i].fa,i);
		Notleaf[a[i].fa]=1;
		//cout<<a[i].fa<<endl;
	}
	build(1);
	for(int i=1;i<=n;i++)
	{
		if(Notleaf[a[i].id]==0)
		{
			//s.insert(a[i]);
			s[++cnts]=a[i];
		}
	}
	sort(s+1,s+cnts+1);
	/*for(int i=1;i<=n;i++)
	{
		cout<<i<<" "<<s[i].dep<<" "<<Notleaf[s[i].id]<<endl;	 
	}*/
	
	maxx=0;
	minn=0x7fffffff;

	for(int i=1;i<=cnts;i++)
	{
		//cout<<s[i].id<<" "<<s[i].dep<<endl;
		sum=0;
		up(s[i].id);
		maxx=max(maxx,sum);
		minn=min(minn,sum);
		//cout<<sum<<endl;
	}
	
	cout<<maxx-minn<<endl;;
	
	return 0;
	
}

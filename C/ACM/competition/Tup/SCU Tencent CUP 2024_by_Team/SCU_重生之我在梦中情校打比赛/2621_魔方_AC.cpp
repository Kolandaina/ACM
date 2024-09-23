#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define maxn 10005
using namespace std;

int t,n;
int a[10],b[10],c[10];
char s[maxn];
set<int>mp;

void init()
{
	for(int i=1;i<=8;++i)
	a[i]=i;
}

pair<int,int>read(int &p)
{
	pair<int,int>ret;
	switch (s[p])
	{
		case 'R':
		{
			ret.first=1;
			break;
		}
		case 'L':
		{
			ret.first=2;
			break;
		}
		case 'U':
		{
			ret.first=3;
			break;
		}
		case 'D':
		{
			ret.first=4;
			break;
		}
		case 'F':
		{
			ret.first=5;
			break;
		}
		case 'B':
		{
			ret.first=6;
			break;
		}
	}
	ret.second=1;
	p++;
	if(p>=n)
	return ret;
	if(s[p]==39)
	{
		p++;
		ret.second=3;
		if(p>=n)
		return ret;
		if(s[p]=='2')
		{
			ret.second=2;
			p++;
		}
		return ret;
	}
	else if(s[p]=='2')
	{
		ret.second=2;
		p++;
	}
	return ret;
}

void move(int x)
{
	switch(x)
	{
		case 1:
		{
			b[1]=2;b[2]=6;b[3]=8;b[4]=4;
			break;
		}
		case 2:
		{
			b[1]=1;b[2]=5;b[3]=7;b[4]=3;
			break;
		}
		case 3:
		{
			b[1]=1;b[2]=5;b[3]=6;b[4]=2;
			break;
		}
		case 4:
		{
			b[1]=3;b[2]=7;b[3]=8;b[4]=4;
			break;
		}
		case 5:
		{
			b[1]=1;b[2]=2;b[3]=4;b[4]=3;
			break;
		}
		case 6:
		{
			b[1]=5;b[2]=6;b[3]=8;b[4]=7;
			break;
		}
	}
	for(int i=1;i<=8;++i)
	c[i]=a[i];
	c[b[1]]=a[b[4]];c[b[2]]=a[b[1]];
	c[b[3]]=a[b[2]];c[b[4]]=a[b[3]];
	for(int i=1;i<=8;++i)
	a[i]=c[i];
}

int check(int x,int y,int z,int l)
{
	b[1]=a[x];b[2]=a[y];b[3]=a[z];b[4]=a[l];
	sort(b+1,b+5);
	int ret=0;
	for(int i=1;i<=4;++i)
	ret=ret*10+b[i];
	if(mp.find(ret)!=mp.end())
	return 1;
	else return 0;
}

void solve()
{
	init();
	scanf("%s",s);
	n=strlen(s);
	int p=0;
	pair<int,int>op;
	while(p<n)
	{
		op=read(p);
		for(int i=1;i<=op.second;++i)
		move(op.first);
	}
	int ans=check(2,4,6,8)&check(1,3,5,7)&check(1,2,5,6)&
			check(3,4,7,8)&check(1,2,3,4)&check(5,6,7,8);
	if(!ans)
	printf("NO\n");
	else printf("YES\n");
}

int main()
{
	mp.insert(1234);mp.insert(5678);mp.insert(1256);
	mp.insert(3478);mp.insert(1357);mp.insert(2468);
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
/*
5
RR'
F2B2
UUU
LDL'D'
R2F'UR'U2R2F'R'U2U'R2U'F2U'R'FR2U'R'URU'R'FU

1

*/

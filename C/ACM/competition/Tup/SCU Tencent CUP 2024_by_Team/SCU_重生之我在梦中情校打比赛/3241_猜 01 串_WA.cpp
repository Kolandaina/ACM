#include<cstdio>
#include<ctime>
#include<algorithm>
#define maxn 2005
using namespace std;

int n;
char s[maxn],t[maxn];

int query(int l,int r,int x,int fl)
{
	printf("? ");
	if(fl)
	printf("%c",x+'0');
	for(int i=l;i<=r;++i)
	printf("%c",s[i]);
	if(!fl)
	printf("%c",x+'0');
	printf("\n");
	fflush(stdout);
	int ret;
	scanf("%d",&ret);
	return ret;
}

int main()
{
	srand(time(NULL));
	scanf("%d",&n);
	int len;
	for(int i=1;i<=n;++i)
	{
		int x=rand()%2;
		int ret=query(1,i-1,x,0);
		if(ret)
		s[i]=x+'0';
		else
		{
			x^=1;
			ret=query(1,i-1,x,0);
			if(ret)
			s[i]=x+'0';
			else
			{
				len=i-1;
				break;
			}
		}
		if(i==n)
		{
			printf("! ");
			for(int j=1;j<=n;++j)
			printf("%c",s[j]);
			printf("\n");
			fflush(stdout);
			return 0;
		}
	}
	for(int i=1;i<=len;++i)
	t[n-len+i]=s[i];
	int st=n-len+1;
	for(int i=st;i<=n;++i)
	s[i]=t[i];
	for(int i=st-1;i>=1;--i)
	{
		int ret=query(i+1,n,0,1);
		if(ret)
		s[i]='0';
		else s[i]='1';
	}
	printf("! ");
	for(int j=1;j<=n;++j)
	printf("%c",s[j]);
	printf("\n");
	fflush(stdout);
	return 0;
}

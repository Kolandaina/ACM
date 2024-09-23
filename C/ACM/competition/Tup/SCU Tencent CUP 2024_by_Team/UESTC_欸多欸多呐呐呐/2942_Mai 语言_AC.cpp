#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int ans[22];
void print()
{
	for(int i=0;i<n;i++)
	{
		printf("{%d}",(1<<i));
		for(int j=1;j<=ans[i];j++) printf(",");
		printf("\n");
	}
}
int findlen(int num)
{
	int len=0;
	while(num)
	{
		len++;
		num/=10;
	}
	return len;
}
int main() {
    scanf("%d %d %d",&n,&m,&k);
    /*if(m==1&&n!=1)
    {
    	cout<<-1;
    	return 0;
	}*/
	if(k==1&&n!=1)
	{
		for(int i=1;i<=n;i++)
		{
			int l=m-findlen(1<<i)-2;
			if(i==n) ans[i]=2;
			else ans[i]=1;
			if(ans[i]>l)
			{
				cout<<-1;
				return 0;
			}
		}
		for(int i=1;i<=n;i++)
	    {
		printf("{%d}",(1<<i));
		for(int j=1;j<=ans[i];j++) printf(",");
		printf("\n");
	    }
		return 0;
	}
    int now=k;
    for(int i=0;i<n-1;i++)
    {
    	int l=m-findlen(1<<i)-2;
    	if(l<=0)
    	{
    		cout<<-1;
    		return 0;
		}
    	if(now<=l)
    	{
    		ans[i]=now-1;
    		now=2;
		}
		else
		{
			ans[i]=l;
			now-=l;
			now*=2;
		}
	}
	int l=m-findlen(1<<(n-1))-2;
	if(now>l||l<=0)
	{
		cout<<-1;
		return 0;
	}
	else ans[n-1]=now;
	print();
	return 0;
}


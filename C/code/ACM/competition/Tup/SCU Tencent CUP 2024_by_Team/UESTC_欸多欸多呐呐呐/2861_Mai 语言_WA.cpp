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
int main() {
    scanf("%d %d %d",&n,&m,&k);
    if(m==1&&n!=1)
    {
    	cout<<-1;
    	return 0;
	}
	if(k==1&&n!=1)
	{
		cout<<-1;
		return 0;
	}
    int now=k;
    for(int i=0;i<n-1;i++)
    {
    	if(now<=m)
    	{
    		ans[i]=now-1;
    		now=2;
		}
		else
		{
			ans[i]=m;
			now-=m;
			now*=2;
		}
	}
	if(now>m)
	{
		cout<<-1;
		return 0;
	}
	else ans[n-1]=now;
	print();
	return 0;
}


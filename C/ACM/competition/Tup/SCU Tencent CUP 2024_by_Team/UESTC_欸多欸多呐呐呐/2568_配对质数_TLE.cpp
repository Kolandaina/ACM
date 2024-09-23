#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int flg[maxn];
int pri[maxn],cnt=0;
void solve(int n)
{
	if(n==0)return;
	if(n==1)
	{
		printf("1 2\n");
		return ;
	}
	int pos=lower_bound(pri+2,pri+1+cnt,2*n)-pri;
	for(int i=pri[pos]-2*n,j=2*n;i<=j;i++,j--)printf("%d %d\n",i,j);
	solve((pri[pos]-2*n-1)/2);
}
int main() {
	
	for(int i=2;i<=maxn-10;i++)
	{
		if(!flg[i])pri[++cnt]=i;
		for(int j=1;j<=cnt&&pri[j]*i<=maxn-10;j++)
		{
			flg[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		solve(n);
	}
	return 0;
}


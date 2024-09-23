#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n=1e6;
int p[N], vis[N], cnt;
inline void init()
{
	for(int i = 2;i < N;i ++)
	{
		if(!vis[i]) p[++ cnt] = i;
		for(int j = 1;j <= cnt && i * p[j] < N;j ++)
		{
			vis[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
}
void sc(int l,int r){
	//cout<<l<<' '<<r<<endl;
	//return;
	for(int i=l;i<=r;i++){
		int l1=i,r1=r+l-l1;
		if(l1<=r1){
			printf("%d %d\n",l1,r1);
		}
	}
}
inline void work()
{
	scanf("%d",&n);
	while(n){
		int r=2*n,l=0;
		int k=upper_bound(p+1,p+cnt+1,2*n)-p;
		n=(p[k]-2*n)/2;
		l=2*n+1;
		sc(l,r);
	}
}
signed main()
{
	init();
	int T; scanf("%d",&T);
	while(T--) work();
	return 0;
}
/*
5 3

10 10
*/

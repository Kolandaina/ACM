#include<bits/stdc++.h>
#define LL long long
using namespace std;

const LL N=1e6+9;

LL n;
bitset<N> f;

void read(LL &x)
{
	scanf("%lld",&x);
}

void solve()
{
	read(n);
	printf("%s\n",f[n]?"Alice":"Bob");
}

void init(LL n)
{
	for(LL i=1;i<=n;++i)
	{
		if(i%2)	f[i]=!f[i-1];
		else	f[i]=!f[i-1]||!f[i/2];
	}
}

int main()
{
	init((LL)1e6);
	
	LL T;
	read(T);
	while(T--)	solve();
	return 0;
}

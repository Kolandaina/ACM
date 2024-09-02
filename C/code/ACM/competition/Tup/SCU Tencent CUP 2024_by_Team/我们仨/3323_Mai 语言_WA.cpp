#include <iostream>
#include <cstdio>
using namespace std;
#define ll long long
#define dis(i) ((ll)(len[i]+(ll)(1<<i)))

ll len[50]={0};
ll in[50]={0},le[50]={0};

ll cal(ll x) {
	ll ret=0;
	while(x) {
		x/=10;
		++ret;
	}
	return (ll)(ret+2);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m,k;
	cin>>n>>m>>k;
	ll i,j;
	for(i=0;i<=30;++i) {
		len[i]=cal((ll)(1<<i));
//		printf("len_%lld=%lld->%lld\n",i,len[i],dis(i));
	}
//	printf("end=%lld\n",end);
	ll inx;
	ll p=0,q;
	for(i=n-1;i>=1;i--) {
//		printf("p=%lld\n",p);
		le[i]=m-len[i];
		if(p&1) {
			if(!(le[i]&1)) {
				--le[i];
			}
		}else {
			if(le[i]&1) {
				--le[i];
			}
		}
		p+=le[i];
		p>>=1;
	}
	le[0]=m-len[0];
	p+=le[0];
	p=p-k;
//	printf("p==%lld\n",p);
	if(k==1) {
		p-=le[0];
	}
	if(p<0) {
		printf("-1\n");
		return 0;
	}
	for(i=0;i<n;++i) {
//		printf("p==%lld [%lld]\n",p,le[i]);
		if(p>0) {
			ll tmp=((ll)(1<<i));
			ll tmp_in=(le[i]-tmp)/((ll)(1<<i));
			if(p<=tmp_in) {
				tmp_in-=p;
				le[i]-=p*((ll)(1<<i));
				p=0;
			}else {
				p-=tmp_in;
				le[i]=tmp;
			}
		}
	}
//	for(i=0;i<n;++i) {
//		printf("%lld\n",le[i]);
//	}
	
//	printf("p==%lld\n",p);
	while(p--) {
		for(i=1;i<n;++i) {
			le[i]-=((ll)(1<<(i-1)));
		}
	}
//		for(i=0;i<=end;++i) {
//			printf("%lld ,%lld\n",in[i],le[i]);
//		}
	bool flag=0;
	for(i=0;i<n;++i) {
		if(le[i]<=0) {
			flag=1;
			break;
		}
	}
	if(flag) {
		printf("-1");
	}else {
		for(i=0;i<n;++i) {
			if(le[i]<=0)
				continue;
			printf("{%lld}",((ll)(1<<i)));
//			printf("%lld\n",le[i]);
			for(j=0;j<le[i];++j) {
				printf(",");
			}
			printf("\n");
		}
	}
	return 0;
}

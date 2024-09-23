#include <cstdio>
#include <cstring>

using namespace std;

const int N=3e6+10;
int primes[N];
int cnt=0;
bool is_prime[N];

int cnt_dfs;
int pei_dui[N][2];
bool flag;
void dfs(int x) {
	if(x<=0||flag==1) {
		return;
	}
	int l=1,r=cnt;
	while(l<r) {
		int mid=(l+r)>>1;
//		printf("mid=%d\n",primes[mid]);
		if(primes[mid]>x) {
			r=mid;
		}else {
			l=mid+1;
		}
	}
//	printf("r=%d\n",r);
	if(x+x-1<primes[r]) {
		flag=1;
		return;
	}
	for(int tmp1=x,tmp2=primes[r]-x;tmp1>tmp2;--tmp1,++tmp2) {
		pei_dui[++cnt_dfs][0]=tmp1;
		pei_dui[cnt_dfs][1]=tmp2;
	}
	dfs(primes[r]-x-1);
	return;
}

int main() {
	
	
	memset(is_prime, true, sizeof is_prime);
	is_prime[1] = false;
	for (int i=2;i<=N-10;++i) {
		if (is_prime[i]) primes[++cnt]=i;
		for(int j=1;j<=cnt&&i*primes[j]<=N;++j) {
			is_prime[i*primes[j]]=false;
			if(!(i%primes[j])) break;
		}
	}
	
//	printf("%d\n");
//	for(int i=1;i<=20;++i) {
//		printf("%d\n",primes[i]);
//	}
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d",&n);
		cnt_dfs=0;
		flag=0;
		dfs(n<<1);
		if(flag) {
			printf("-1\n");
		}else {
			for(int i=1;i<=cnt_dfs;++i) {
//				for(int j=0;j<=1;++j) {
					printf("%d %d",pei_dui[i][0],pei_dui[i][1]);
//				}
				printf("\n");
			}
		}
	}
	return 0;
}


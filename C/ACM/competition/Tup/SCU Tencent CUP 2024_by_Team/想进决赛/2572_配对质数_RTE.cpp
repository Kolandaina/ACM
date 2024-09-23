#include <iostream>
using namespace std;

const int N = 1e6;
int T,n,m;
int v[N+5], prime[N+5];

void primes(){
	for (int i = 2; i <= N; i ++){
		if (v[i] == 0)
		  v[i] = i, prime[++ m] = i;
		for (int j = 1; j <= m; j ++){
			if (prime[j] > v[i] || prime[j] > N/i)
			   break;
			v[i*prime[j]] = prime[j];
		}
	}
}

void show(int x, int y){
	for (int i = 1; i <= x; i ++)
	  printf("%d %d\n",i,2*x-i+1);
	for (int i = 1; i <= y-x; i ++)
	  printf("%d %d\n",2*x+i,2*y-i+1);
}

int main(){
	primes();
	scanf("%d",&T);
	while (T --){
		scanf("%d",&n);
		int flag = 1;
		for (int k = n; k >= 1; k --){
			if (v[2*k+1] == 2*k+1 && v[2*(k+n)+1] == 2*(k+n)+1){
				show(k,n);
				flag = 0;
				break;
			}
		}
		if (flag)
		  printf("-1\n");
	}
	return 0;
}


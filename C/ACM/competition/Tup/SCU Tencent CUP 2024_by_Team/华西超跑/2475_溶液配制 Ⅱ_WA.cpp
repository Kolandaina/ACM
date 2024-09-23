#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
#define P 1000000007
#define D double
const D PIE=acos(-1);
int pw[2001];
D a[2000],b[2000];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		pw[i]=(pw[i-1]*2+1)%P;
	}
	for(int i=0;i<n;i++){
		scanf("%lf%lf",a+i,b+i);
	}
	for(int i=0;i<q;i++){
		D x,y;
		scanf("%lf%lf",&x,&y);
		vector<D>A;
		for(int j=0;j<n;j++){
			if(a[j]!=x||b[j]!=y){
				A.push_back(atan2(b[j]-y,a[j]-x));
			}
		}
		sort(A.begin(),A.end());
		int s=A.size();
		for(int j=0;j<s;j++){
			A.push_back(A[j]+PIE*2);
		}
		int ans=pw[n],r=0;
		for(int j=0;j<s;j++){
			while(A[r]-A[j]<PIE){
				r++;
			}
			ans-=pw[r-j-1]+1;
			ans%=P;
		}
		ans=(ans+P)%P;
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 4
0 0
20 0
0 20
20 20
10 10
0 0
30 20.5
0.001 0
*/

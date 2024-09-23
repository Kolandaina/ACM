#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 200001
vector<int>G[N];
int p[N],len[N],f[N];
void Solve(int x){
	int h,l=N;
	for(int T:G[x]){
		Solve(T);
		if(len[T]<l){
			l=len[T];
			h=T;
		}
	}
	if(l==N){
		len[x]=1;
	}else{
		len[x]=l+1;
		p[x]=h;
	}
}
int main(){
	int n;
	scanf("%d",&n);
	if(n==1){
		printf("0");
		return 0;
	}
	for(int i=2;i<=n;i++){
		scanf("%d",f+i);
		G[f[i]].push_back(i);
	}
	for(int T:G[1]){
		Solve(T);
	}
	int l=N,r=0;
	for(int i=2;i<=n;i++){
		if(p[f[i]]!=i){
			l=min(l,len[i]);
			r=max(r,len[i]);
		}
	}
	printf("%d",r-l);
	return 0;
}
/*
6
1 2 2 4 1
*/

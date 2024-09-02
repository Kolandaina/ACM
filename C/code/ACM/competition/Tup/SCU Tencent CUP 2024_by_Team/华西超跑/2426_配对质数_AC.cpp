#include<bits/stdc++.h>
using namespace std;
#define N 2100000
bool vis[2100000];
int ans[1000001];
void Solve(int n){
	int p=n<<1|1;
	while(vis[p]==false){
		p++;
	}
	int x=p-(n<<1),d=n;
	while(x<(n<<1)){
		ans[d]=x;
		x+=2;
		d--;
	}
	if(d>0){
		Solve(d);
	}
}
int main(){
	for(int i=2;i<N;i++){
		vis[i]=true;
	}
	for(int i=2;i<N;i++){
		if(vis[i]==true){
			for(int j=i<<1;j<N;j+=i){
				vis[j]=false;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int n;
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			ans[j]=0;
		}
		Solve(n);
		for(int j=1;j<=n;j++){
			printf("%d %d\n",j<<1,ans[j]);
		}
	}
	return 0;
}

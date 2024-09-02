#include<iostream>
#include<algorithm>
using namespace std;
int f1[2001],f2[2001],f3[2001];
void Solve(int n,int m,int*F){
	for(int i=1;i<=n;i++){
		F[i]=-1e8;
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		for(int j=n;j>=a;j--){
			F[j]=max(F[j],F[j-a]+b);
		}
	}
	for(int i=1;i<=n;i++){
		F[i]=max(F[i],F[i-1]);
	}
}
int main(){
	int n,m1,m2,m3;
	cin>>n>>m1>>m2>>m3;
	Solve(n,m1,f1);
	Solve(n,m2,f2);
	Solve(n,m3,f3);
	long long ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;i+j<=n;j++){
			ans=max(ans,(long long)f1[i]*f2[j]*f3[n-i-j]);
		}
	}
	cout<<ans;
	return 0;
}
/*
10 2 2 2
2 1
3 2
2 1
3 2
5 3
4 2
*/

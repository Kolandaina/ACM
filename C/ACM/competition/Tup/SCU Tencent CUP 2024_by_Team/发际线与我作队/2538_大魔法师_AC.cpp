#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m1,m2,m3;
int a[N],b[N],c[N];
int v1[N],v2[N],v3[N];
int dp1[N],dp2[N],dp3[N];
void sovle(){
	cin>>n>>m1>>m2>>m3;
	for(int i=1;i<=m1;i++){
		cin>>v1[i]>>a[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>v2[i]>>b[i];
	}
	for(int i=1;i<=m3;i++){
		cin>>v3[i]>>c[i];
	}
	
	for(int i=1;i<=m1;i++){
		for(int j=2000;j>=v1[i];j--){
			dp1[j]=	max(dp1[j],dp1[j-v1[i]]+a[i]);
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=2000;j>=v2[i];j--){
			dp2[j]=	max(dp2[j],dp2[j-v2[i]]+b[i]);
		}
	}
	for(int i=1;i<=m3;i++){
		for(int j=2000;j>=v3[i];j--){
			dp3[j]=	max(dp3[j],dp3[j-v3[i]]+c[i]);
		}
	}
	
	long long res = 0;
	for(int i = n; i >= 1; --i){
		for(int j = n; j >= 1; --j){
			int k = n - i - j;
			if(k <= 0)
				continue;
			else{
				res = max(res, (long long)dp1[i] * dp2[j] * dp3[k]);
			}
		}
	}

	cout<<res<<endl;
}
int main(){
	sovle();
}

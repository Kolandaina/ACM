#include<bits/stdc++.h>
#define int long long
using namespace std;
int f1[20005],f2[20005],f3[20005];
int w1[20005],w2[20005],w3[20005],v1[20005],v2[20005],v3[20005];
void save_the_people(){
	int n,m1,m2,m3;
	cin>>n>>m1>>m2>>m3;
	for(int i=1;i<=m1;i++){
	cin>>w1[i]>>v1[i];
}
	for(int i=1;i<=m2;i++){
	cin>>w2[i]>>v2[i];
}
	for(int i=1;i<=m3;i++){
	cin>>w3[i]>>v3[i];
}
	for(int i=1;i<=m1;i++){
		for(int j=n;j>=w1[i];j--){
			f1[j]=max(f1[j],f1[j-w1[i]]+v1[i]);
		}
	}
		for(int i=1;i<=m2;i++){
		for(int j=n;j>=w2[i];j--){
			f2[j]=max(f2[j],f2[j-w2[i]]+v2[i]);
		}
	}
		for(int i=1;i<=m3;i++){
		for(int j=n;j>=w3[i];j--){
			f3[j]=max(f3[j],f3[j-w3[i]]+v3[i]);
		}
	}
	int ans=0;
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		if(n-i-j>=0)
		ans=max(f1[i]*f2[j]*f3[n-i-j],ans);
	}
}
cout<<ans;
}
signed main(){
	int ttt=1;
	while(ttt--){
		save_the_people();
	}
	return 0;
}

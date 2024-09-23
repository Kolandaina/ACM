#include<bits/stdc++.h>
using namespace std;
const int N=2e3+5;
int n,m1,m2,m3;
int a[N],b[N],c[N];
int v1[N],v2[N],v3[N];
int cnt[N];
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
		cnt[v3[i]]=max(cnt[v3[i]],c[i]);
	}
	for(int i=1;i<=2001;i++){
		cnt[i]=max(cnt[i],cnt[i-1]);	
	}
	
	int ans=0;
	for(int i=1;i<=m1;i++){
		for(int j=1;j<=m2;j++){
			int t=v1[i]+v2[j];
			if(t>=n)continue;
			int res=n-t;
			ans=max(ans,a[i]*b[j]*cnt[res]);
		}
	}
	cout<<ans<<endl;
}
int main(){
	sovle();
}

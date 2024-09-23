#include<bits/stdc++.h>
using namespace std;
int f1[20005],f2[20005],f3[20005];
int w1[20005],w2[20005],w3[20005],v1[20005],v2[20005],v3[20005];
void save_the_people(){
//	for(int i=0;i<=20005;i++)
//	f1[i]=1,f2[i]=1,f3[i]=1;
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
			if(w1[i]<=j){
				int f=0;
				if(f1[j-w1[i]]==0) {
				f1[j-w1[i]]=1;
				f=1;
			}
			f1[j]=max(f1[j],f1[j-w1[i]]*v1[i]);
			if(f)
			{
				f1[j-w1[i]]=0;
			}
		}
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=n;j>=w2[i];j--){
			int f=0;
			if(f2[j-w2[i]]==0)
			{
				f2[j-w2[i]]=1;
				f=1;
			}
			f2[j]=max(f2[j],f2[j-w2[i]]*v2[i]);
			if(f)
			{
				f2[j-w2[i]]=0;
			}
		}
	}
	for(int i=1;i<=m3;i++){
		for(int j=n;j>=w3[i];j--){
			int f=0;
			if(f3[j-w3[i]]==0)
			{
				f3[j-w3[i]]=1;
				f=1;
			}
			f3[j]=max(f3[j],f3[j-w3[i]]*v3[i]);
			if(f)
			{
				f3[j-w3[i]]=0;
			}
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i;j++){
			if(n-i-j>0)
			ans=max(ans,f2[i]*f3[j]*f1[n-i-j]);
		}
	}
	if(ans==-1) cout<<0<<endl;
	else
	cout<<ans;
}

int main(){
//	phii();
	//cout<<tot;
	int ttt=1;
//	cin>>ttt;
	while(ttt--){
		save_the_people();
	}
	return 0;
}

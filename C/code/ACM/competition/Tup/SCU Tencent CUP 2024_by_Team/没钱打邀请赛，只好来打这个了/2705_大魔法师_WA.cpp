#include<bits/stdc++.h>
using namespace std;
int f1[20005],f2[20005],f3[20005];
int w1[20005],w2[20005],w3[20005],v1[20005],v2[20005],v3[20005];
int num1,num2,num3,rnum1,rnum2,rnum3;
void save_the_people(){
	for(int i=0;i<=20005;i++)
	f1[i]=1,f2[i]=1,f3[i]=1;
	int n,m1,m2,m3;
	cin>>n>>m1>>m2>>m3;
	for(int i=1;i<=m1;i++){
	cin>>w1[i]>>v1[i];
	num1=min(num1,w1[i]);
	if(w1[i]>=n)
	rnum1++;
}
	for(int i=1;i<=m2;i++){
	cin>>w2[i]>>v2[i];
		if(w2[i]>=n)
	rnum2++;
	num2=min(num2,w2[i]);
}
	for(int i=1;i<=m3;i++){
	cin>>w3[i]>>v3[i];
	num3=min(num3,w3[i]);
	if(w3[i]>=n)
	rnum3++;
}
if(rnum1==m1||rnum2==m2||rnum3==m3){
	cout<<"0";
	return;
}
	for(int i=1;i<=m1;i++){
		for(int j=n;j>=w1[i];j--){
			f1[j]=max(f1[j],f1[j-w1[i]]*v1[i]);
		}
	}
	for(int i=1;i<=m2;i++){
		for(int j=n;j>=w2[i];j--){
			f2[j]=max(f2[j],f2[j-w2[i]]*v2[i]);
		}
	}
	for(int i=1;i<=m3;i++){
		for(int j=n;j>=w3[i];j--){
			f3[j]=max(f3[j],f3[j-w3[i]]*v3[i]);
		}
	}
	int ans=-1;
	for(int i=num2;i<=n;i++){
		for(int j=num3;j<=n;j++){
			if(n-i-j>=num1)
			ans=max(ans,f2[i]*f3[j]*f1[n-i-j]);
		}
	}
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

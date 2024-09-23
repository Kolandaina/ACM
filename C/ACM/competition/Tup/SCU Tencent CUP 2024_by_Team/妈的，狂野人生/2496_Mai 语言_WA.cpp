#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=1e6+10;
int pre[p];

signed main(){
	int n,m,k;
	std::cin>>n>>m>>k;
	int a[11] = {1,2,4,8,16,32};
	if(k>6||n!=k){
		cout<<"-1"<<endl;
		return 0;
	}
	if(k>=4&&a[k]+4>m){
		cout<<"-1"<<endl;
		return 0;
	}
	if(k<4&&a[k]+3>m){
		cout<<"-1"<<endl;
		return 0;
	}
	for(int i=0;i<n;i++){
		cout<<"{"<<a[i]<<"}";
		for(int j=1;j<=a[i];j++)cout<<",";
		cout<<endl;
	}
     return 0;
    
}

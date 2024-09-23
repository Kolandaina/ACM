#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
const int mod = 1e9 + 7;

int getl(int x){
	int res=1;
	while(x){
		res++;
		x/=10;
	}
	return res;
}

void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	queue<array<int,2>>q;
	int res=k,t=1,cnt=1;
	for(int i=1;i<31;i++,res*=2,t*=2){
		if(k==0) break;
		int ans=res;
		int len=getl(t);
		if(ans+len+2<=m){
			res=0;
			if(n>1){
				ans--;
				res++;
			}
		}
		else{
			ans=ans%m-len-2;
			res-=ans;
		}
		if(ans){
			n--;
			q.push({t,ans});
		}
	}
	if(n) cout<<"-1"<<endl;
	else{
		while(q.size()){
			auto as=q.front();
			q.pop();
			cout<<"{"<<as[0]<<"}";
			for(int i=0;i<as[1];i++) cout<<",";
			cout<<endl;
		}
	}
}
signed main(){
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back 
const int N=100013;
const ld pi=3.14159265358979323846264;
vector<int>mp[N];
#define mid ((l+r)>>1)
#define ls l,mid,x<<1
#define rs mid+1,r,x<<1|1
int dep[N],son[N];
int l,r;
void dfs(int x){
	int md=10000000;
	for(auto i:mp[x]){
		dfs(i);
		md=min(md,dep[i]+(x!=1));
	}
	if(md>N)md=1;
	dep[x]=md;
	for(auto i:mp[x])if(dep[i]+1==dep[x])son[x]=i;
}
void dfs2(int x,int tp){
	if(x==tp)l=min(l,dep[x]),r=max(r,dep[x]);
	for(auto i:mp[x]){
		if(son[x]==i)dfs2(i,tp);
		else dfs2(i,i);
	}
}
void solve(){
	int n;cin>>n;
	l=n,r=0;
	for(int i=2,x;i<=n;i++)cin>>x,mp[x].push_back(i);
	dfs(1);
	dfs2(1,1);
	cout<<r-l<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	int T=1;
	cout<<fixed<<setprecision(15);
	//cin>>T;
	while(T--)solve();
}

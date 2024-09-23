#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back 
const int N=300013;
const ld pi=3.14159265358979323846264;
vector<int>mp[N];
#define mid ((l+r)>>1)
#define ls l,mid,x<<1
#define rs mid+1,r,x<<1|1
const int mod=998244353;
int a[N];
ll pw[N];

void solve(){
	int n,q;
	cin>>n>>q;
	string s;
	for(int i=1;i<=n;i++){
		cin>>s;
		int v=0;
		for(auto c:s)if(isdigit(c))v=v*10+c-48;
		a[v+1]++;
	}
	for(int i=1;i<N;i++)a[i]+=a[i-1];
	while(q--){
		cin>>s;
		int v=0;
		for(auto c:s)if(isdigit(c))v=v*10+c-48;
		v++;
		int l=a[v-1];
		int r=n-a[v];
		cout<<(1+pw[n]-pw[l]-pw[r]+mod+mod)%mod<<'\n';
	}
}

int main(){
	pw[0]=1;
	for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%mod;
	ios::sync_with_stdio(false);
	int T=1;
	cout<<fixed<<setprecision(15);
	//cin>>T;
	while(T--)solve();
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define push_back pb
const int N=4000013;
int mp[N],p[N],tot;
void solve(){
	int n;
	cin>>n;n=n+n;
	int a=0,b=0;
	if(n==2){
		cout<<1<<' '<<2<<'\n';
		return;
	}
	for(int i=1;i<=n;i++)if(mp[i]==i&&mp[n+i]==n+i)a=i,b=n+i;
	if(a==0){
		cout<<-1<<'\n';
	}else{
		for(int i=1;a-i>i;i++)cout<<i<<' '<<a-i<<'\n';
		for(int i=a;b-i>i;i++)cout<<i<<' '<<b-i<<'\n';
	}
}

int main(){
	for(int i=2;i<N;i++){
		if(!mp[i])mp[i]=i,p[++tot]=i;
		for(int j=1;j<=tot;j++){
			if(p[j]*i>=N)break;
			mp[p[j]*i]=p[j];
			if(mp[i]==p[j])break;
		}
	}
	int T=1;
	cin>>T;
	while(T--)solve();
}

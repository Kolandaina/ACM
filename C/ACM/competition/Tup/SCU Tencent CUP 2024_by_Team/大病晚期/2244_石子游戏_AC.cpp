#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define push_back pb
const int N=2000013;
int f[N];

void solve(){
	int n;
	cin>>n;
	if(f[n]==1){
		cout<<"Alice\n";}
		else{
			cout<<"Bob\n";}
}

int main(){
	ios::sync_with_stdio(false);
	f[1]=1;
	for(int i=2;i<N;i++){
		if(i&1)f[i]=f[i-1]^1;
		else{
			f[i]=f[i-1]&f[i/2],f[i]^=1;
		}
	}
	int T=1;
	cin>>T;
	while(T--)solve();
}

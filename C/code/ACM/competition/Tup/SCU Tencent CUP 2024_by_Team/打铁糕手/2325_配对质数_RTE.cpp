#include<bits/stdc++.h>
#define int long long

using namespace std;


int p[400006],cnt=0;
int flag[4000006];
int fac[4000006];

int fact(int n){
	for(int i=2;i<=n;i++){
		if(!flag[i]){
			p[cnt++]=i;
			fac[i]=1;
		}
		for(int j=0;p[j]<=n/i;j++){
			int t=p[j]*i;
			flag[t]=1;
			if(i%p[j]==0){
				break;
			}
			
		}
	}
}


void solve() {
	int n;
	cin>>n;
	if(fac[2*n+1]){
		for(int i=1;i<2*n+1-i;i++){
			cout<<i<<' '<<2*n+1-i<<endl;
		}
	}else{
		int f=0,mi;
		for(int i=1;i<n;i++){
			if(fac[2*i+1]&&fac[2*i+1+2*n]){
				for(int j=1;j<2*i+1-j;j++){
					cout<<j<<' '<<2*i+1-j<<endl;
				}
				for(int j=2*i+1;j<2*n+1-j+2*i;j++){
					cout<<j<<' '<<2*n+1-j+2*i<<endl;
				}
				f=1;
				break;
			}
		}
		if(!f){
			cout<<-1<<endl;
		}
	}
}

int32_t main() {
	int t = 1; cin >> t;
	fact(4e6);
	
	while (t --) {
		solve();
	}
	return 0;
}


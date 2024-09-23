#include<bits/stdc++.h>
//#define int long long
#define endl '\n'

using namespace std;


int p[400006],cnt=0;
int flag[5000666];

int fact(int n){
	for(int i=2;i<=n;i++){
		if(!flag[i]){
			p[cnt++]=i;
		}
		for(int j=0;j < cnt && p[j] * i <=n;j++){
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
	if(!flag[2*n+1]){
		for(int i=1;i<2*n+1-i;i++){
			cout<<i<<' '<<2*n+1-i<<endl;
		}
	}else{
		int f=0,mi;
		for(int i=1;i<n;i++){
			if(!flag[2*i+1]&&!flag[2*i+1+2*n]){
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1; cin >> t;
	fact(4e6+100);
	
	while (t --) {
		solve();
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
const int mod = 1e9 + 7;
int p[1000100];
vi ans;
void ols(){
	p[0] = p[1] = 1;
	for(int i = 2; i<=1000000;i++){
		if(!p[i]){
			ans.push_back(i);
			for(int j =i;j<=1000000/i;j++)p[i*j]=1;
		}
	}
}
void solve(){
	int n;
	cin >> n;
//	while(1){
		int tmp = n*2;
		int f = 0;
		for(int i = 0; ;i++){
			if(p[ans[i]]==0&&p[ans[i]+tmp]==0){
				f=ans[i];
				break;
			} 
			if(ans[i] > tmp){
				cout << -1 << endl;
				return;
			}
		}
		if(f!=0){
			for(int  i = 1;i < f;i+=2){
				cout << i << " " << f-i << endl;
			}
			for(int i = f; i<=tmp;i+=2){
				cout << i << " " << tmp+f-i << endl;
			}
		}	
//	}
}
signed main(){
	int _=1;
	cin>>_;
	ols();
	while(_--) solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
const int mod = 1e9 + 7;
int p[4000100];
vi ans;
void ols(){
	p[0] = p[1] = 1;
	for(int i = 2; i<=4000000;i++){
		if(!p[i]){
			ans.push_back(i);
			for(int j =i;j<=4000000/i;j++)p[i*j]=1;
		}
	}
}
//int n = 0;
void solve(){
	int n;
	cin >> n;
//	n++;
//	cout << ans[100] << endl;
//	fopen("1.txt","w",stdout);
//	while(1){
		int tmp = n*2;
		int f = 0;
		int l=0,r=ans.size()-1;
		while(l<r){
			int mid=l+r>>1;
			if(ans[mid]>=tmp) r=mid;
			else l=mid+1;
		}
		for(int i = l;ans[i] < 620;i++){
			if(p[ans[i]]==0&&p[ans[i]-tmp]==0){
				f=ans[i]-tmp;
//				cout << f << " ";return;
//				if(f>500){
//					cout << n   << " "<< f << endl;
////					exit(0);
//					return;
//				}
				break;
			} 
//			if(ans[i] > tmp){
//				cout << -1 << endl;
//				return;
//			}
		}
		if(f!=0){
			for(int  i = 1;i < f;i+=2){
				cout << i << " " << f-i << endl;
			}
			for(int i = f; i<=tmp;i+=2){
				cout << i << " " << tmp+f-i << endl;
			}
		}
		else cout<<"-1\n";	
//	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _=1;
	cin>>_;
	ols();
	while(_--) solve();
	return 0;
}

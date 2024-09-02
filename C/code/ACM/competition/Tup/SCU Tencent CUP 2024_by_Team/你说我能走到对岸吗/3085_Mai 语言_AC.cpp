#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
void solve(){
	int n,m,k;
	cin>>n>>m>>k;
	double sum=0;
	vector<string> ans;
	//printf("%d %d %d\n",'{','}',',');if (n > 
	int cnt=0;
	int i=0;
	while(cnt<n&&i<30){
		int x=(1<<i);
		string s;
		s='{'+to_string(x)+'}';
		for(int j=s.size();j<=m-1;j++){
			if(sum+(1.0/x)<k){
				s+=',';
				sum+=(1.0/x);
			}
			else if(sum+(1.0/x)==k&&cnt==n-1){
				s+=',';
				sum+=(1.0)/x;
			}
			else{
				break;
			}
		}
		if(s[s.size()-1]==',') {
			cnt++;
			ans.push_back(s);
		}
		i++;
	}
	if(sum==k){
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<'\n';
		}
	}
	else cout<<-1;
}
signed main(){
	int _ = 1;
	//cin >> _;
	for(int i = 1;i<=_;i++){
		solve();
	}
	return 0;
}

#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

vector<vector<int> > b;
vector<int > f;
set<int> q;

int  dfs(int x){
	multiset<int> a;
	for(int i=0;i<b[x].size();i++){
		if(!f[b[x][i]]){
			f[b[x][i]]=1;
			int c=dfs(b[x][i]);
		a.insert(c);	
		}
	}
	if(a.size()==0)
		{
			return 1;
		}
	if(x!=1){
		int num=*a.begin();
		a.erase(a.begin());
		for(auto i:a){
			q.insert(i);
		}
		return num+1;
	}
	else{
		for(auto i:a){
		q.insert(i);
	}
	return 0;
	}
}

void solve() {
	int n,m,x;
	std::cin >> n;	
	b.resize(n + 1);
	f.resize(n+1);
	for(int i=2;i<=n;i++){
		cin>>x;
		b[x].push_back(i);
		b[i].push_back(x);
	} 
	f[1]=1;
	dfs(1);
	cout<<*q.rbegin()-*q.begin()<<"\n";
}

signed main () {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);

	int t = 1;
//	cin >> t;
	for(int i = 0; i < t; ++i) solve ();

	return 0;
}

//3 3
//10.000
//15.000
//16.000
//00.000
//15.000
//15.999

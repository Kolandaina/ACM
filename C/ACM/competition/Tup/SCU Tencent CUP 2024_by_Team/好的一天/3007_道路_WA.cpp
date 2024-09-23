#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

vector<vector<int> > b;
vector<int > f;


multiset<int>  dfs(int x){
	multiset<int> a;
	for(int i=0;i<b[x].size();i++){
		if(!f[b[x][i]]){
			f[b[x][i]]=1;
			multiset<int> c=dfs(b[x][i]);
		if(c.size()>a.size())
			swap(a,c);
		for(auto j = c.begin(); j != c.end(); j++){
			a.insert(*j);
		}	
		}
		
	}
	if(a.size()==0)
		a.insert(0);
	if(x!=1){
		int num=*a.begin();
		a.erase(a.begin());
		a.insert(num+1);
	}
	return a;
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
	multiset<int> d=dfs(1);
	cout<<*d.rbegin()-*d.begin()<<"\n";
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

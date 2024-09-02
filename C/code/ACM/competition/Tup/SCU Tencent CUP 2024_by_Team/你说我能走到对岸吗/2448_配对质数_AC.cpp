#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 5e6 + 10;
const int mod = 1e9 + 7;
int n, m ,k;
unordered_set<int> s;
int inq[N];
vector<int> a1;
void solve(int x){
	cin >> n;
	if(s.count((1 + 2 * n))){
		for(int i =1;i<=n;i++){
			cout << i <<" " << 2 * n - i + 1 <<endl;
		}
		return;
	}else{
		for(int i = 3;i<=2 * n - 2;i+=2){
			if(s.count(i + 2 * n) && s.count(i)){
				int l = 1, r = i-1;
				while (l < r)cout << l++ << ' ' << r-- << endl;
				l = i, r = 2 * n;
				while (l < r)cout << l++ << ' ' << r-- << endl;
				return;
			}
		}
	}
	cout << -1 <<endl;
}
signed main(){
	int _ = 1;
	for (int i=2; i<N; i++){
		if (!inq[i])a1.pb(i);
		for (int j=0; j<a1.size() && a1[j] * i < N; j++)
		{
			inq[a1[j] * i] = 1;
			if (i % a1[j] == 0)break;
		}
	}
	for (auto i : a1)s.insert(i);
	cin >> _;
	for(int i = 1;i<=_;i++){
		solve(i);
	}
	return 0;
}

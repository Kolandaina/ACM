#include<bits/stdc++.h>
#define eps 1e-8
#define MAXN 100000+5
using namespace std;
//const int N=1e5+5;
//int n,m;

const int MOD = 1e9+7;

double sw[MAXN];
int sum[MAXN];
int cnt = 0;


// first number that is larger than w
// very little: return 0
// very large: return cnt
int binarySearch(double w){
	int l = 0;
	int r = cnt;
	int mid = (l + r) >> 1;
	int ans = cnt;
	while(l <= r){
		mid = (l + r) >> 1;
		if(sw[mid] > w){
			ans = mid;
			r = mid - 1;
		}
		else{
			l = mid + 1;
		}
	}
	return ans;
}

long long binpow(long long a, long long b, long long m) {
//	a %= m;
//	long long res = 1;
//	while(b > 1) {
//		if(b & 1)
//			res = res * a % m;
//		a = a * a % m;
//		b >>= 1;
//	}
	long long base = a;
	long long res = 1;
	while(b){
		if(b&1)
			res = (res * base) % m;
		base = (base* base) % m;
		b >>= 1;
	}
	return res;
}

long long count1(int n, int m, int a){
	long long res = 0;
	res = res + ((binpow(2, n, MOD) - 1)%MOD) * ((binpow(2, m, MOD) - 1)%MOD) % MOD;
	// cout << "res = " << res << endl;
	res = (res + ((binpow(2, a, MOD) - 1)%MOD) * (binpow(2, n + m, MOD) % MOD)) % MOD;
	return res;
}


struct cmp{
	bool operation(double& d1, double& d2){
		return abs(d1 - d2) > eps;
	}
};



void solve(){
	int n, q;
//	auto f = [](double d1, double d2) {
//		return abs(d1 - d2) > eps;
//	};
	map<double, int> mp;
	double w;
	cin >> n >> q;
	for(int i = 0; i < n; ++i){
		cin >> w;
		mp[w] += 1;
	}
	for(map<double,int>::iterator it = mp.begin(); it != mp.end(); ++it){
		sw[cnt++] = it -> first;		
		// cout << it->first << " " << it->second << endl;
	}
	sort(sw, sw + cnt);
	for(int i = 0; i < cnt; ++i){
		if(i == 0){
			sum[i] = mp[sw[i]];
		}
		else{
			sum[i] = sum[i-1] + mp[sw[i]];
		}
//		cout << sw[i] << " : " << sum[i] << endl;
	}
	
	for(int i = 0; i < q; ++i){
		cin >> w;
		int index = binarySearch(w);
		if(index == 0 || index == cnt){
			cout << 0 << endl;
		}
		else{
			int _index = index - 1;
			int __index = _index - 1;
			int nn = 0; // small
			int aa = 0; // equal
			int mm = 0; // large
			
			if(_index < 0){
				cout << 0 << endl;
			}
			else{
				if(abs(sw[_index] - w) < eps){
					aa = mp[sw[_index]];
					if(__index >= 0){
						nn = sum[__index];
					}
				}
				else{
					nn = sum[_index];
				}
				
				mm = sum[cnt - 1] - nn - aa;
			}
//			cout << "non - zero" << endl;
			// cout << nn << " " << aa << " " << mm << endl;
			cout << count1(nn,mm,aa) << endl;
		}
		
	}
	
}
int main(){
	// freopen("F.txt", "rb", stdin);
	solve();
}

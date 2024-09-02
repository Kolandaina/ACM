#include <bits/stdc++.h>

#define int long long

std::vector<int> a;

int dp(int l, int r, std::vector<std::vector<int>> &p){
	if(l >= r) return 0;
	if(p[l][r] == -1){
		p[l][r] = 0;
		p[l][r] = std::max(p[l][r], (a[l] + a[l + 1]) % 3 + dp(l + 2, r, p));
		p[l][r] = std::max(p[l][r], (a[r] + a[r - 1]) % 3 + dp(l, r - 2, p));
		p[l][r] = std::max(p[l][r], (a[l] + a[r]) % 3 + dp(l + 1, r - 1, p));
	}
	return p[l][r];
}

signed main(){
	int n;
	std::cin >> n;
	a.resize(n);
	for(auto &i : a) std::cin >> i;

	std::vector<std::vector<int>> f(n, std::vector<int>(n, -1));

	std::cout << dp(0, n - 1, f);

	return 0;
}
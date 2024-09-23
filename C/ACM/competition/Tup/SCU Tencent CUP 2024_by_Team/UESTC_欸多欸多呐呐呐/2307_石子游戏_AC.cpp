#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int res[N];
bool dfs(int n) {
	if (res[n] != -1) {
		return res[n];
	}
	if (n == 1) {
		return (res[1] = 1);
	}
	if (n & 1) {
		res[n] = !dfs(n - 1);
	} else {
		res[n] = !(dfs(n - 1) && dfs(n / 2));
	}
	return res[n];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	memset(res, -1, sizeof(res));
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		bool ans = dfs(n);
		cout << (ans ? "Alice\n" : "Bob\n");
	}
	return 0;
}


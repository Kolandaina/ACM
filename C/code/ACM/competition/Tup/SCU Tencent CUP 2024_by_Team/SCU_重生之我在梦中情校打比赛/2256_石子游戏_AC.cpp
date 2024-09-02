#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;

int t, n;
int f[N];

void prep() {
	for (int i = 1; i < N; ++i) {
		if (i & 1) {
			f[i] = (f[i - 1] ^ 1);
		}
		else {
			f[i] |= (f[i - 1] ^ 1) | (f[i / 2] ^ 1); 
		}
	}
}

void charming() {
	cin >> n;
	if (f[n]) cout << "Alice" << endl;
	else cout << "Bob" << endl; 
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	prep();
	cin >> t;
	while (t--) charming();
	return 0;
}

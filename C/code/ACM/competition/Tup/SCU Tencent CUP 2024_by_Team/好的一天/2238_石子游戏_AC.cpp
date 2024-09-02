#include <bits/stdc++.h>

int main () {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::vector<int> f(1000001);

	f[1] = 1;
	for(int i = 2; i <= 1000000; i++) {
		int t = f[i - 1];
		if(i % 2 == 0) t = std::min(t, f[i - i / 2]);
		if(t) f[i] = 0;
		else f[i] = 1;
	}

	int t;
	std::cin >> t;
	for(int i= 0 ; i <t; i ++) {
		int n;
		std::cin >> n;
		std::cout << (f[n] ? "Alice\n" : "Bob\n");
	}

	return 0;
}

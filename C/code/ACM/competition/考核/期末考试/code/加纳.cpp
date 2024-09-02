#include <bits/stdc++.h>

int main(){
	int n, m, k;
	std::cin >> n >> m >> k;
	std::cout << (k / n + ((k % n) >= m));

	return 0;
}
#include <bits/stdc++.h>

int main(){
	int n, res = 0;
	std::cin >> n;
	std::array<int, 100000> a;

	for(int i = 0; i < n; i++){
		std::cin >> a[i];
		if(i == 0) res += a[i];
		else if(i > 0 && a[i] > a[i - 1]){
			res += a[i] - a[i - 1];
		}
	}
	std::cout << res;

	return 0;
}
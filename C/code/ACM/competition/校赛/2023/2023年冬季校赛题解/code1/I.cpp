#include <bits/stdc++.h>

void solved (){
	int n, m, x, y, z;
	std::cin >> n >> m >> x >> y >> z;

	if(x >= z){
		std::cout << "0\n";
		return ;
	}

	int res = (z - x + y - 1) / y;
	if(n == 1 && res > 1){
		std::cout << "-1\n";
	}
	else {
		std::cout << res << '\n';
	}
}

int main(){
	int t;
	std::cin >> t;

	for(int i = 0; i < t; ++i) solved ();

	return 0;
}
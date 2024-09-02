#include <bits/stdc++.h>

int main(){
	int res = 0, day = 0;
	int M;
	std::cin >> M;

	for(int i = 0; i < M; i++){
		int m;
		std::cin >> m;
		for(int j = 1; j <= m; j++){
			if(j == 19 && day == 6){
				res++;
			}
			day = (day + 1) % 7;
		}
	}
	std::cout << res;

	return 0;
}
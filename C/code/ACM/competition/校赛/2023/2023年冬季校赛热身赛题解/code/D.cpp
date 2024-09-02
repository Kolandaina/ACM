#include <bits/stdc++.h>

int main(){
	int n, cnt = 0;
	long long sum = 0;
	while(std::cin >> n){
		cnt++;
		sum += n;
		if(cnt == 7){
			std::cout << sum << '\n';
			sum = cnt = 0;
		}
	}

	return 0;
}
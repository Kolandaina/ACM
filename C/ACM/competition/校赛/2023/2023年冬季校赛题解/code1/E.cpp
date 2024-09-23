#include <bits/stdc++.h>

void solved (){
	long long a, b, c, d;
	std::cin >> a >> b >> c >> d;
	long long A = a * d + b * c;
	long long B = b * d;
	long long res = (A + B - 1) / B;
	std::cout << res << '\n';
}

int main(){
	int t;
	std::cin >> t;
	for(int i = 0; i < t; ++i) solved ();

	return 0;
}
#include <bits/stdc++.h>

#define int long long

signed main() {
	std::string s;

	std::getline(std::cin, s);

	for(auto i : s){
		std::cout << i;
		if(i == '.') std::cout << "xixixixi.";
	}
}
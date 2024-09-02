#include <bits/stdc++.h>

int main(){
	std::string s;
	std::cin >> s;
	std::vector<int> a, cnt(26, 0);

	for(int i = 0; i < (int)s.size(); i++) {
		cnt[(int)(s[i] - 'a')]++;
		if(cnt[(int)(s[i] - 'a')] == 1) a.push_back((int)(s[i] - 'a'));
	}

	int q;
	std::cin >> q;
	for(int i = 0; i < q; i++){
		int op;
		char c;
		std::cin >> op;
		if(op == 1) {
			std::cin >> c;
			cnt[(int)(c - 'a')]++;
			if(cnt[(int)(c - 'a')] == 1) a.push_back((int)(c - 'a'));

		}
		else if(op == 2) {
			std::sort(a.begin(), a.end(), [&](int A, int B){
				if(cnt[A] == cnt[B]) return A < B;
				return cnt[A] > cnt[B];
			});
			for(int i = 0; i < (int)a.size(); i++) std::cout << (char)(a[i] + 'a') << " \n"[i == (int)a.size() - 1];
		}
	}

	return 0;
}
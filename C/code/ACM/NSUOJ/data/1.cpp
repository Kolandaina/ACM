#include <bits/stdc++.h>

#include "carefree.hpp"
using namespace carefree;

#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
#define fs(x) std::fixed << std::setprecision(x)
inline void slove()
{
	gen_data(1, 1, [&](int i, int j) {
		testcase_io io("", i, j);
		int n = 1e7;
		if (i == 1) n = 10;
		if (i == 2) n = 100;
		if (i == 3) n = 1000;
		if (i == 4) n = 1e5;
		int a = randint(1, n), b = randint(1, n);
		io.input_write(a, b);
		io.output_write(a + b);
	});
}
signed main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t = 1;
	// std:: cin >> t;
	while (t--) slove();
	return 0;
}


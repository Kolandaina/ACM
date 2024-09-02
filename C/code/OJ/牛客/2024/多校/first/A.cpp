#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = INT64_MAX;
#define fs(x) std::fixed << std::setprecision(x)
inline void slove()
{
	int n, m, q;
	std::cin >> n >> m >> q;
	std::vector<int> k (N), C (N);
	for (int i = (k[0] = 1); i <= n; i++)k[i] = k[i - 1] * 2 % q;
	for (int i = (C[0] = 1); i <= n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			C[j] = (C[j] + C[j - 1]) % q;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt1 = 1, cnt2 = 1;
		for (int j = 1; j <= m - 1; j++)
		{
			cnt1 = cnt1 * k[n - i] % q;
			cnt2 = cnt2 * (k[i] - 1) % q;
		}
		ans = (ans + cnt1 * cnt2 % q * C[i]) % q;
	}
	std::cout << (ans % q + q) % q << endl;
}
signed main()
{
	std::ios_base::sync_with_stdio (false);
	std::cin.tie (nullptr);
	std::cout.tie (nullptr);
	int t = 1;
	// std:: cin >> t;
	while (t--) slove();
	return 0;
}

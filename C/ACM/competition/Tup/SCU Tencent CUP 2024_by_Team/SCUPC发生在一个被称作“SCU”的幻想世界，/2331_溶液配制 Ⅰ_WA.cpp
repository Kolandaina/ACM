#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6 + 10, mod = 1e9 + 7;

int n, q;
int pre[N];
map<int, int> cnt;

int stoint(string s)
{
	if (s.size() == 0)
		return 0;
	int p = 1, ans = 0;
	for (int i = s.size() - 1; i >= 0; i--)
		ans += (s[i] - '0') * p, p *= 10;
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	string s;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int x = stoint(s.substr(0, 2)) * 1000 + stoint(s.substr(3, 3));
		pre[x]++;
		cnt[x]++;
	}
	for (int i = 1; i <= N - 5; i++)
		pre[i] += pre[i - 1];
	for (int i = 1; i <= q; i++)
	{
		int ans = 0;
		cin >> s;
		int x = stoint(s.substr(0, 2)) * 1000 + stoint(s.substr(3, 3));
		int t = pre[x];
		if (cnt.count(x))
			t -= cnt[x];
		ans += t * (n - t) % mod;
		ans %= mod;
		if (cnt.count(x))
			ans += cnt[x] * (n - cnt[x]) % mod + (cnt[x] * (cnt[x] - 1) / 2) % mod, ans %= mod;
		cout << ans << endl;
	}
	return 0;
}

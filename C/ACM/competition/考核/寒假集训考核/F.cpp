#include <bits/stdc++.h>
using namespace std;
const int N = 100000;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		map<int, int> mymap;
		string s = "";
		int n = 0, r = 0, l = 0, m = 0;
		int dp[N];
		memset(dp, 0, sizeof(dp));
		cin >> n;
		cin >> s;
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			if (s[i - 1] == '0')
				dp[i] = dp[i - 1] - 1;
			else
				dp[i] = dp[i - 1] + 1;
		}
		for (int i = 1; i <= n; i++)
		{
			l = mymap[dp[i]];
			if (l == 0 && dp[i] != 0)
				mymap[dp[i]] = i;
			else if (i - l > m)
			{
				m = i - l;
				r = l;
			}
		}
		cout << m << endl;
	}
	return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
// #define endl "\n"
// typedef long long ll;
// const int N = 2e5 + 10, M = 2e5 + 10, inf = 1e8;
// int n, m, k;
// string s;
// map<int, int> mp;
// int main()
// {
// 	IOS;
// 	int t = 1;
// 	cin >> t;
// 	while (t--)
// 	{
// 		mp.clear();
// 		int cur = 0;
// 		int ans = 0;
// 		mp[0] = -1;
// 		cin >> n >> s;
// 		for (int i = 0; i < n; i++)
// 		{
// 			if (s[i] == '1')
// 			{
// 				cur++;
// 			}
// 			else
// 			{
// 				cur--;
// 			}
// 			if (!mp.count(cur))
// 			{
// 				mp[cur] = i;
// 			}
// 			else
// 			{
// 				ans = max(ans, i - mp[cur]);
// 			}
// 		}
// 		cout << ans << endl;
// 	}
// 	return 0;
// }
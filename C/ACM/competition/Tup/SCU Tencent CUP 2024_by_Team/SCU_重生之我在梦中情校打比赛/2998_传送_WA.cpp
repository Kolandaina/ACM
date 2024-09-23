#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 5;
 
bool cmp (pair<pair<int, int>, pair<int, int> > x, pair <pair<int, int>, pair<int, int> > y) {
	return x.first.first < y.first.first;
}

int t, n, m;

void charming() {
	cin >> n >> m;
	vector<pair<pair<int, int>, pair<int, int> > > seg(m);
	for (int i = 0; i < m; ++i) {
		cin >> seg[i].first.first >> seg[i].first.second;
		cin >> seg[i].second.first >> seg[i].second.second;
	}
	/*sort(seg.begin(), seg.end(), [](pair<pair<int, int>, pair<int, int> > &x,
	pair<pair<int, int>, pair<int, int> > &y) {
		return x.first.first < y.first.first;
	});*/
	sort(seg.begin(), seg.end(), cmp);
	vector<pair<pair<int, int>, pair<int, int> > > nseg;
	for (int i = 0; i < m; ++i) {
		if (nseg.empty () || nseg.back().first.second < seg[i].first.first) {
			nseg.emplace_back(seg[i]);
		}
		else {
			nseg.back().first.second = max(nseg.back().first.second, seg[i].first.second);
			nseg.back().second.first = min(nseg.back().second.first, seg[i].second.first);
			nseg.back().second.second = max(nseg.back().second.second, seg[i].second.second);
		}
	}
	
	seg = nseg; m = seg.size();
	vector<int> vis(n + 1);
	vector<pair<pair<int, int>, pair<int, int> > > stk;
	vector<vector<int> > vec(n + 1);
	for (int i = 0, c = 0; i < m; ++i) {
		if (stk.empty() || stk.back().second.second < seg[i].first.first) {
			stk.emplace_back(seg[i]), c += 1;
			vec[c].emplace_back(i);
		}
		else {
			vec[c].emplace_back(i);
			// stk.back().first.second = max(stk.back().first.second, seg[i].first.second);
			stk.back().second.first = min(stk.back().second.first, seg[i].second.first);
			stk.back().second.second = max(stk.back().second.second, seg[i].second.second);
		}
	}
	vector<pair<int, int> > ans (n + 1);
	for (int i = 1; i <= n; ++i) ans[i] = make_pair(i, i);
	for (int i = 1; i <= stk.size(); ++i) {
		auto it = stk[i - 1];
		int a = it.first.first, b = it.first.second;
		int c = it.second.first, d = it.second.second;
		for (int j = 0; j < vec[i].size(); ++j) {
			for (int k = seg[vec[i][j]].first.first; 
			k <= seg[vec[i][j]].first.second; ++k) {
				ans[k].first = min(ans[k].first, c);
				ans[k].second = max(ans[k].second, d);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> t;
	while (t--) charming();
	return 0;
}

/*
3 3
10.000
15.000
16.000
00.000
15.000
15.999
*/

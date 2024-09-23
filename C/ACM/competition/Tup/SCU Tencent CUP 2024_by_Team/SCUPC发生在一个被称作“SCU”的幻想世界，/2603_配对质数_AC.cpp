#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back

typedef vector<int> vi;

const int N = 4e6 + 10;

vi p;
bool ntp[N];

void init()
{
	for (int i = 2; i <= N - 5; i++)
	{
		if (ntp[i])
			continue;
		p.pb(i);
		for (int j = i * i; j <= N - 5; j += i)
			ntp[j] = true;
	}
}

bool check(int n) {
	int x = 2 * n;
	while (true) {
		int y = 1;
		while (ntp[x + y]) {
			y += 2;
		}
		for (int i = x; i > y; i -= 2) {
			cout << i << ' ' << (x + y - i) << '\n';
		}
		if (y == 1) {
			return 1;
		}
		x = y - 1;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
//	for (int i = 0; i < 100; i++)
//		cout << p[i] << endl;
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		check(n);
	}
	return 0;
}

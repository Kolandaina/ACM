#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	long double r, x;
	cin >> r >> x;
	long double thita = x / r;
	cout << fixed << setprecision(12) << (1.L / cos(thita) - 1) * x << '\n';
	return 0;
}


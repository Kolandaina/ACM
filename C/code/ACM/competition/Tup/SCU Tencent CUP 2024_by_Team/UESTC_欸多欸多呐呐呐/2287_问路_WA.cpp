#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	double r, x;
	cin >> r >> x;
	double thita = acos(-1) / 2 - x / r;
	cout << fixed << setprecision(12) << (1 / sin(thita) - 1) * x << '\n';
	return 0;
}


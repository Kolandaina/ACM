#include <bits/stdc++.h>

typedef long long ll;

const int N = 2100;


void solve()
{
	double r, x; std::cin >> r >> x;
	double a = x/r;
	double b = acos(-1)/2.0-a;
	double len = x/sin(b)-x;
	//printf("%0.6lf\n",len);
	double c = 2*acos(-1)*r;
	while(len>c) len -= c;
	printf("%0.7lf\n",std::min(len,c-len));
}

signed main()
{
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);
	
	int t = 1;
	//std::cin >> t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);

	int T;
	cin >> T;
	char ch = char(39);
	while (T--) {
		int a[6][4];
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 4; ++j) {
				a[i][j] = i;
			}
		}
		string s;
		cin>> s;
		int n = s.length();
		
		auto rotate1 = [&](int &a, int &b, int &c, int &d) {
			int t = d;
			d = c;
			c = b;
			b = a;
			a = t;	
		};
		
		auto rotate2 = [&](int &a, int &b, int &c, int &d, int &e, int &f, int &g, int &h) {
			int t1 = g, t2 = h;
			g = e;
			h = f;
			f = d;
			e = c;
			d = b;
			c = a;
			b = t2;
			a = t1;
		};
		
		auto U = [&]() {
			rotate1(a[5][0], a[5][1], a[5][2], a[5][3]);
			rotate2(a[0][0], a[0][1], a[3][0], a[3][1], a[2][0], a[2][1], a[1][0], a[1][1]);
		};
		

		
		auto R = [&]() {
			rotate1(a[1][0], a[1][1], a[1][2], a[1][3]);
			rotate2(a[0][1], a[0][2], a[5][1], a[5][2], a[2][3], a[2][0], a[4][1], a[4][2]);
		};
		

		
		auto F = [&]() {
			rotate1(a[0][0], a[0][1], a[0][2], a[0][3]);
			rotate2(a[5][3], a[5][2], a[1][0], a[1][3], a[4][1], a[4][0], a[3][2], a[3][1]);
		};
		

		
		auto D = [&]() {
			rotate1(a[4][0], a[4][1], a[4][2], a[4][3]);
			rotate2(a[0][3], a[0][2], a[1][3], a[1][2], a[2][3], a[2][2], a[3][3], a[3][2]);
		};
		
		auto L = [&]() {
			rotate1(a[3][0], a[3][1], a[3][2], a[3][3]);
			rotate2(a[5][0], a[5][3], a[0][0], a[0][3], a[4][0], a[4][3], a[2][2], a[2][1]);
		};
		
		auto B = [&]() {
			rotate1(a[2][0], a[2][1], a[2][2], a[2][3]);
			rotate2(a[5][0], a[5][1], a[3][3], a[3][0], a[4][2], a[4][3], a[1][1], a[1][2]);
		};
		
		
		for (int i = 0; i < n; ++i) {
			bool flag = 0, flag1 = 0;
			if (s[i] == ch || s[i] == '2') {
				continue;
			}
			if (i + 1 < n && s[i + 1] == ch) {
				flag = 1;
			}
			if (i + 1 < n && s[i + 1] == '2') {
				flag1 = 1;
			}
			if (s[i] == 'U') {
				int cnt = 1;
				if (flag) {
					cnt = 3;
				}
				if (flag1) {
					cnt = 2;
				}
				for (int i = 0; i < cnt; ++i) {
					U();
				}
			} else if (s[i] == 'D') {
				int cnt = 1;
				if (flag) {
					cnt = 3;
				}
				if (flag1) {
					cnt = 2;
				}
				for (int i = 0; i < cnt; ++i) {
					D();
				}
			} else if (s[i] == 'F') {
				int cnt = 1;
				if (flag) {
					cnt = 3;
				}
				if (flag1) {
					cnt = 2;
				}
				for (int i = 0; i < cnt; ++i) {
					F();
				}				
			} else if (s[i] == 'B') {
				int cnt = 1;
				if (flag) {
					cnt = 3;
				}
				if (flag1) {
					cnt = 2;
				}
				for (int i = 0; i < cnt; ++i) {
					B();
				}				
			} else if (s[i] == 'L') {
				int cnt = 1;
				if (flag) {
					cnt = 3;
				}
				if (flag1) {
					cnt = 2;
				}
				for (int i = 0; i < cnt; ++i) {
					L();
				}				
			} else if (s[i] == 'R') {
				int cnt = 1;
				if (flag) {
					cnt = 3;
				}
				if (flag1) {
					cnt = 2;
				}
				for (int i = 0; i < cnt; ++i) {
					R();
				}				
			}
		}
		
		auto check = [&]() {
			bool flag = 1;
			for (int i = 0; i < 6; ++i) {
				int ori = a[i][0];
				for (int j = 1; j < 4; ++j) {
					if (ori != a[i][j]) {
						return false;
					}
				}
			}
			return true;
		};
		
		//for (int i = 0; i < 6; ++i) {
			//for (int j = 0;j < 4; ++j) {
			//	cout << a[i][j];
			//}
			//cout << "\n";
		//}
		
		cout << (check() ? "YES\n" : "NO\n");
	}
	

	
	return 0;
}


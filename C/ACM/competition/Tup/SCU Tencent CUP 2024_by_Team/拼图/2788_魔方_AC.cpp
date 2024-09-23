#include <bits/stdc++.h>
using namespace std;
struct Block {
	vector<int> col;
	Block(): col(6) { }
	void clear() {
		for (auto &x: col) x = 0;
	}
	void print() {
		cout << "( ";
		for (auto &x: col) cout << x << " ";
		cout << ")";
	}
};
Block M[2][2][2];
void R(Block M[2][2][2]) {
	auto x = M[0][0][0];
	M[0][0][0].clear();
	M[0][0][0].col[1] = M[1][0][0].col[6];
	M[0][0][0].col[6] = M[1][0][0].col[3];
	M[0][0][0].col[2] = M[1][0][0].col[2];
	M[1][0][0].clear();
	M[1][0][0].col[3] = M[1][0][1].col[5];
	M[1][0][0].col[6] = M[1][0][1].col[3];
	M[1][0][0].col[2] = M[1][0][1].col[2];
	M[1][0][1].clear();
	M[1][0][1].col[3] = M[0][0][1].col[5];
	M[1][0][1].col[5] = M[0][0][1].col[1];
	M[1][0][1].col[2] = M[0][0][1].col[2];
	M[0][0][1].clear();
	M[0][0][1].col[1] = x.col[6];
	M[0][0][1].col[5] = x.col[1];
	M[0][0][1].col[2] = x.col[2];
}
void L(Block M[2][2][2]) {
	auto x = M[0][1][0];
	M[0][1][0].clear();
	M[0][1][0].col[1] = M[0][1][1].col[5];
	M[0][1][0].col[6] = M[0][1][1].col[1];
	M[0][1][0].col[4] = M[0][1][1].col[4];
	M[0][1][1].clear();
	M[0][1][1].col[1] = M[1][1][1].col[5];
	M[0][1][1].col[5] = M[1][1][1].col[3];
	M[0][1][1].col[4] = M[1][1][1].col[4];
	M[1][1][1].clear();
	M[1][1][1].col[5] = M[1][1][0].col[3];
	M[1][1][1].col[3] = M[1][1][0].col[6];
	M[1][1][1].col[4] = M[1][1][0].col[4];
	M[1][1][0].clear();
	M[1][1][0].col[3] = x.col[6];
	M[1][1][0].col[6] = x.col[1];
	M[1][1][0].col[4] = x.col[4];
}
void U(Block M[2][2][2]) {
	auto x = M[0][0][1];
	M[0][0][1].clear();
	M[0][0][1].col[1] = M[1][0][1].col[2];
	M[0][0][1].col[2] = M[1][0][1].col[3];
	M[0][0][1].col[5] = M[1][0][1].col[5];
	M[1][0][1].clear();
	M[1][0][1].col[2] = M[1][1][1].col[3];
	M[1][0][1].col[3] = M[1][1][1].col[4];
	M[1][0][1].col[5] = M[1][1][1].col[5];
	M[1][1][1].clear();
	M[1][1][1].col[3] = M[0][1][1].col[4];
	M[1][1][1].col[4] = M[0][1][1].col[1];
	M[1][1][1].col[5] = M[0][1][1].col[5];
	M[0][1][1].clear();
	M[0][1][1].col[4] = x.col[1];
	M[0][1][1].col[1] = x.col[2];
	M[0][1][1].col[5] = x.col[5];
}
void D(Block M[2][2][2]) {
	auto x = M[0][0][0];
	M[0][0][0].clear();
	M[0][0][0].col[1] = M[0][1][0].col[4];
	M[0][0][0].col[2] = M[0][1][0].col[1];
	M[0][0][0].col[6] = M[0][1][0].col[6];
	M[0][1][0].clear();
	M[0][1][0].col[4] = M[1][1][0].col[3];
	M[0][1][0].col[1] = M[1][1][0].col[4];
	M[0][1][0].col[6] = M[1][1][0].col[6];
	M[1][1][0].clear();
	M[1][1][0].col[4] = M[1][0][0].col[3];
	M[1][1][0].col[3] = M[1][0][0].col[2];
	M[1][1][0].col[6] = M[1][0][0].col[6];
	M[1][0][0].clear();
	M[1][0][0].col[3] = x.col[2];
	M[1][0][0].col[2] = x.col[1];
	M[1][0][0].col[6] = x.col[6];
}
void F(Block M[2][2][2]) {
	auto x = M[0][0][0];
	M[0][0][0].clear();
	M[0][0][0].col[2] = M[0][0][1].col[5];
	M[0][0][0].col[6] = M[0][0][1].col[2];
	M[0][0][0].col[1] = M[0][0][1].col[1];
	M[0][0][1].clear();
	M[0][0][1].col[5] = M[0][1][1].col[4];
	M[0][0][1].col[2] = M[0][1][1].col[5];
	M[0][0][1].col[1] = M[0][1][1].col[1];
	M[0][1][1].clear();
	M[0][1][1].col[5] = M[0][1][0].col[4];
	M[0][1][1].col[4] = M[0][1][0].col[6];
	M[0][1][1].col[1] = M[0][1][0].col[1];
	M[0][1][0].clear();
	M[0][1][0].col[6] = x.col[2];
	M[0][1][0].col[4] = x.col[6];
	M[0][1][0].col[1] = x.col[1];
}
void B(Block M[2][2][2]) {
	auto x = M[1][0][0];
	M[1][0][0].clear();
	M[1][0][0].col[2] = M[1][1][0].col[6];
	M[1][0][0].col[6] = M[1][1][0].col[4];
	M[1][0][0].col[3] = M[1][1][0].col[3];
	M[1][1][0].clear();
	M[1][1][0].col[6] = M[1][1][1].col[4];
	M[1][1][0].col[4] = M[1][1][1].col[5];
	M[1][1][0].col[3] = M[1][1][1].col[3];
	M[1][1][1].clear();
	M[1][1][1].col[5] = M[1][0][1].col[2];
	M[1][1][1].col[4] = M[1][0][1].col[5];
	M[1][1][1].col[3] = M[1][0][1].col[3];
	M[1][0][1].clear();
	M[1][0][1].col[5] = x.col[2];
	M[1][0][1].col[2] = x.col[6];
	M[1][0][1].col[3] = x.col[3];
}
void R_re(Block M[2][2][2]) {
	R(M); R(M); R(M);
}
void L_re(Block M[2][2][2]) {
	L(M); L(M); L(M);
}
void U_re(Block M[2][2][2]) {
	U(M); U(M); U(M);
}
void D_re(Block M[2][2][2]) {
	D(M); D(M); D(M);
}
void F_re(Block M[2][2][2]) {
	F(M); F(M); F(M);
}
void B_re(Block M[2][2][2]) {
	B(M); B(M); B(M);
}
bool check(Block M[2][2][2]) {
	int f = M[0][0][0].col[1];
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (M[0][i][j].col[1] != f) return false;
	
	f = M[0][0][0].col[2];
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (M[i][0][j].col[2] != f) return false;
	
	f = M[0][0][0].col[6];
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (M[i][j][0].col[6] != f) return false;
	
	f = M[1][1][1].col[5];
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (M[i][j][1].col[5] != f) return false;
	
	f = M[1][1][1].col[3];
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (M[1][i][j].col[3] != f) return false;
	
	f = M[1][1][1].col[4];
	for (int i = 0; i < 2; ++i)
	for (int j = 0; j < 2; ++j)
	if (M[i][1][j].col[4] != f) return false;
	
	return true;
}
void solve() {
	string s;
	cin >> s;
	int n = s.length();
	M[0][0][0].col = {0, 1, 2, 0, 0, 0, 6};
	M[0][0][1].col = {0, 1, 2, 0, 0, 5, 0};
	M[0][1][0].col = {0, 1, 0, 0, 4, 0, 6};
	M[0][1][1].col = {0, 1, 0, 0, 4, 5, 0};
	M[1][0][0].col = {0, 0, 2, 3, 0, 0, 6};
	M[1][0][1].col = {0, 0, 2, 3, 0, 5, 0};
	M[1][1][0].col = {0, 0, 0, 3, 4, 0, 6};
	M[1][1][1].col = {0, 0, 0, 3, 4, 5, 0};
	for (int i = 0; i < n; ++i) {
		char ch = s[i];
		if (i + 1 < n) {
			if (s[i + 1] == '2') {
				switch(ch) {
					case 'R': R(M); R(M); break;
					case 'U': U(M); U(M); break;
					case 'F': F(M); F(M); break;
					case 'L': L(M); L(M); break;
					case 'D': D(M); D(M); break;
					case 'B': B(M); B(M); break;
				}
				++i;
			} else if (s[i + 1] == '\'') {
				switch(ch) {
					case 'R': R_re(M); break;
					case 'U': U_re(M); break;
					case 'F': F_re(M); break;
					case 'L': L_re(M); break;
					case 'D': D_re(M); break;
					case 'B': B_re(M); break;
				}
				++i;
			} else {
				switch(ch) {
					case 'R': R(M); break;
					case 'U': U(M); break;
					case 'F': F(M); break;
					case 'L': L(M); break;
					case 'D': D(M); break;
					case 'B': B(M); break;
				}
			}
		} else {
			switch(ch) {
				case 'R': R(M); break;
				case 'U': U(M); break;
				case 'F': F(M); break;
				case 'L': L(M); break;
				case 'D': D(M); break;
				case 'B': B(M); break;
			}
		}
	}
//	for (int i = 0; i < 4; ++i) B(M);
//	for (int i = 0; i < 2; ++i) {
//		for (int j = 0; j < 2; ++j) {
//			for (int k = 0; k < 2; ++k) {
//				cout << i << " " << j << " " << k << " ";
//				M[i][j][k].print();
//				cout << endl;
//			}
//		}
//	}
	if (check(M)) cout << "YES\n";
	else cout << "NO\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
//	t = 1;
	while (t--) solve();
	return 0;
}
/*
1
R2F'UR'U2R2F'R'U2U'R2U'F2U'R'FR2U'R'URU'R'FU
*/

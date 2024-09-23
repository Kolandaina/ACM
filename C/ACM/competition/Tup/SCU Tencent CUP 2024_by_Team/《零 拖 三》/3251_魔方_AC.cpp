#include <bits/stdc++.h>

using namespace std;

int read(){
	int res=0,sign=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')sign=-sign;
	for(;'0'<=ch&&ch<='9';ch=getchar()){
		res=(res<<3)+(res<<1)+(ch^'0');
	}
	return res*sign;
}

#define rep(i,l,r) for(int i=l;l<=r;++i)
#define dep(i,r,l) for(int i=r;i>=l;--i)
// shang, xia, zuo, you, qian, hou
vector<vector<int>> cube{{0,0,0,0},{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5}};
void modify(char dir) {
	vector<vector<int>> tmp = cube;
	if (dir == 'U') {
		cube[0][0] = tmp[0][2];
		cube[0][1] = tmp[0][0];
		cube[0][2] = tmp[0][3];
		cube[0][3] = tmp[0][1];
		cube[4][0] = tmp[3][0];
		cube[4][1] = tmp[3][1];
		cube[3][0] = tmp[5][0];
		cube[3][1] = tmp[5][1];
		cube[5][0] = tmp[2][0];
		cube[5][1] = tmp[2][1];
		cube[2][0] = tmp[4][0];
		cube[2][1] = tmp[4][1];
	}
	if (dir == 'D') {
		cube[1][0] = tmp[1][2];
		cube[1][1] = tmp[1][0];
		cube[1][2] = tmp[1][3];
		cube[1][3] = tmp[1][1];
		cube[3][2] = tmp[4][2];
		cube[3][3] = tmp[4][3];
		cube[5][2] = tmp[3][2];
		cube[5][3] = tmp[3][3];
		cube[2][2] = tmp[5][2];
		cube[2][3] = tmp[5][3];
		cube[4][2] = tmp[2][2];
		cube[4][3] = tmp[2][3];
	}
	if (dir == 'L') {
		cube[2][0] = tmp[2][2];
		cube[2][1] = tmp[2][0];
		cube[2][2] = tmp[2][3];
		cube[2][3] = tmp[2][1];
		cube[4][0] = tmp[0][0];
		cube[4][2] = tmp[0][2];
		cube[1][0] = tmp[4][0];
		cube[1][2] = tmp[4][2];
		cube[5][1] = tmp[1][2];
		cube[5][3] = tmp[1][0];
		cube[0][0] = tmp[5][3];
		cube[0][2] = tmp[5][1];
	} 
	if (dir == 'R') {
		cube[3][0] = tmp[3][2];
		cube[3][1] = tmp[3][0];
		cube[3][2] = tmp[3][3];
		cube[3][3] = tmp[3][1];
		cube[0][1] = tmp[4][1];
		cube[0][3] = tmp[4][3];
		cube[4][1] = tmp[1][1];
		cube[4][3] = tmp[1][3];
		cube[1][3] = tmp[5][0];
		cube[1][1] = tmp[5][2];
		cube[5][2] = tmp[0][1];
		cube[5][0] = tmp[0][3];
	}
	if (dir == 'F') {
		cube[4][0] = tmp[4][2];
		cube[4][1] = tmp[4][0];
		cube[4][2] = tmp[4][3];
		cube[4][3] = tmp[4][1];
		cube[3][0] = tmp[0][2];
		cube[3][2] = tmp[0][3];
		cube[1][0] = tmp[3][2];
		cube[1][1] = tmp[3][0];
		cube[2][1] = tmp[1][0];
		cube[2][3] = tmp[1][1];
		cube[0][3] = tmp[2][1];
		cube[0][2] = tmp[2][3];
	}
	if (dir == 'B') {
		cube[5][0] = tmp[5][2];
		cube[5][1] = tmp[5][0];
		cube[5][2] = tmp[5][3];
		cube[5][3] = tmp[5][1];
		cube[0][0] = tmp[3][1];
		cube[0][1] = tmp[3][3];
		cube[2][2] = tmp[0][0];
		cube[2][0] = tmp[0][1];
		cube[1][2] = tmp[2][0];
		cube[1][3] = tmp[2][2];
		cube[3][3] = tmp[1][2];
		cube[3][1] = tmp[1][3];
 }
}
map<string, int> mp;
bool judge(vector<vector<int>>& cube) {
	for (int i = 0; i < 6; ++i) {
		int x = cube[i][0];
		for (int j = 0; j < 4; ++j) {
			if (cube[i][j] != x) return false;
		}
	}
	return true;
}
void solve() {
	cube = {{0,0,0,0},{1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5}};
	string s; cin >> s;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '\'' || s[i] == '2') {
			continue;
		}
		if (i != s.size()-1) {
			if (s[i + 1] == '\'') {
				modify(s[i]); modify(s[i]); modify(s[i]);
				++i; continue;
			} else if (s[i + 1] == '2') {
				modify(s[i]); modify(s[i]); ++i; continue;
			} else {
				modify(s[i]);
			}
		} else {
			modify(s[i]);
		}
	}
//	for (auto i : cube) {
//		for (auto j : i) {
//			cout << j << " ";
//		} cout << endl;
//	}
	if (judge(cube)) cout << "YES" << endl;
	else cout << "NO" << endl;
}
int main(){
	mp["U"] = 0; mp["D"] = 1; mp["L"] = 2 ;mp["R"] = 3 ;mp["F"] = 4; mp["B"] = 5;
	int t = read();
	while (t--) solve();
	return 0;
}

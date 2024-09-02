#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
#define rep(i, l, r) for(ll i = (l); i <= (r); ++i)
#define rep_(i, l, r) for(ll i = (l); i >= (r); --i)
#define endl '\n'
const ll N = 20 +7, P = 1e9 + 7, INF = 1e18;
int p[9], a[9];

void R(int num,int op) {
	rep(j ,1, num) {
		rep(i, 1, 8) a[i] = p[i];
		if(op == 1) {
			a[3] = p[4]; a[4] = p[8]; a[7] = p[3]; a[8] = p[7];
		}
		else {
			a[4] = p[3],a[8] = p[4],a[3] = p[7],a[7] = p[8];
		}
		rep(i, 1, 8) p[i] = a[i];
	}
}
void U(int num,int op) {
	rep(j ,1, num) {
		rep(i, 1, 8) a[i] = p[i];
		if(op == 1) {
			a[2] = p[3]; a[3] = p[7]; a[6] = p[2]; a[7] = p[6];
		}
		else {
			a[3] = p[2],a[7] = p[3],a[2] = p[6],a[6] = p[7];
		}
		rep(i, 1, 8) p[i] = a[i];
	}
}
void F(int num,int op) {
	rep(j ,1, num) {
		rep(i, 1, 8) a[i] = p[i];
		if(op == 1) {
			a[1] = p[4]; a[2] = p[1]; a[3] = p[2]; a[4] = p[3];
		}
		else {
			a[4] = p[1],a[1] = p[2],a[2] = p[3],a[3] = p[4];
		}
		rep(i, 1, 8) p[i] = a[i];
	}
}
void D(int num,int op) {
	rep(j ,1, num) {
		rep(i, 1, 8) a[i] = p[i];
		if(op == 1) {
			a[1] = p[5]; a[4] = p[1]; a[5] = p[8]; a[8] = p[4];
		}
		else {
			a[5] = p[1],a[1] = p[4],a[8] = p[5],a[4] = p[8];
		}
		rep(i, 1, 8) p[i] = a[i];
	}
}
void B(int num,int op) {
	rep(j ,1, num) {
		rep(i, 1, 8) a[i] = p[i];
		if(op == 1) {
			a[5] = p[6]; a[6] = p[7]; a[7] = p[8]; a[8] = p[5];
		}
		else {
			a[6] = p[5],a[7] = p[6],a[8] = p[7],a[5] = p[8];
		}
		rep(i, 1, 8) p[i] = a[i];
	}
}
void L(int num,int op) {
	rep(j ,1, num) {
		rep(i, 1, 8) a[i] = p[i];
		if(op == 1) {
			a[1] = p[2]; a[2] = p[6]; a[5] = p[1]; a[6] = p[5];
		}
		else {
			a[2] = p[1],a[6] = p[2],a[1] = p[5],a[5] = p[6];
		}
		rep(i, 1, 8) p[i] = a[i];
	}
}

bool check() {
	bool flag = true;
	rep(i,1,8) {
		if(p[i] != i) flag = false;
	}
	if(flag) cout << "YES" << endl;
	return flag;
}
	
void solve() {
	string s; cin >> s; s += "____";
	rep(i, 1, 8) p[i] = i;
	ll k = 0;
	while(k < s.size()) {
	if(s[k] == '2' || s[k] == '\'') {
		++k; continue;
	}
	if(s[k] == '_') break;
	char c = s[k];
	ll num = 1;
	ll op = 1;
	if(s[k + 1] == 39) {
		op = 2;
		if(s[k + 2] == '2') num = 2;
	}
	else if(s[k + 1] == '2') num = 2;
	
	if(c == 'R') { R(num, op); }
	else if(c == 'U') { U(num,op); }
	else if(c == 'F') { F(num,op); }
	else if(c == 'D') { D(num,op); }
	else if(c == 'B') { B(num,op); }
	else if(c == 'L') { L(num,op); }
	++k;
	}
	bool ff = false;
	ff = check();
	if(ff) return;
	rep(j,1,4){
		rep(i,1,4){
			F(1,1); B(1,2);
			ff = check();
			if(ff) return;
		}
		U(1,1); D(1,2);
	}
	rep(j,1,4){
		rep(i,1,4){
			F(1,1); B(1,2);
			ff = check();
			if(ff) return;
		}
		R(1,1); L(1,2);
	}
	cout << "NO" << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T(1); 
	cin >> T;
	while (T--) solve();
	return 0;
}

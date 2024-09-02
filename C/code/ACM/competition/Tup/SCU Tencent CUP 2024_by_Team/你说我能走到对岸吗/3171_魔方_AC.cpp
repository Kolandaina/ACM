#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define pb push_back
#define endl '\n'

#define ll long long
#define int ll
const int N = 5e6 + 10;
const int mod = 1e9 + 7;

void solve(){
	int a[9] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
	string s;
	cin >> s;
	vector<string>op;
	for (int i = 0; i<s.size(); i++){
		if (i != s.size() - 1 && !(s[i + 1] >= 'A'&&s[i + 1] <= 'Z')){
			string aa;
			aa = aa + s[i] + s[i + 1];
			op.pb(aa);
			i++;
		}
		else{
			string aa;
			aa = aa + s[i] + ' ';
			op.pb(aa);
		}
	}
	for (int i = 0; i<op.size(); i++){
		if (op[i][0] == 'R'){
			if (op[i][1] == '\''){
				int fl;
				fl = a[2];
				a[2] = a[6], a[6] = a[8], a[8] = a[4], a[4] = fl;
			}
			else if (op[i][1] == '2'){
				int fl;
				fl = a[2];
				a[2] = a[6], a[6] = a[8], a[8] = a[4], a[4] = fl;
				fl = a[2];
				a[2] = a[6], a[6] = a[8], a[8] = a[4], a[4] = fl;

			}
			else{
				int fl;
				fl = a[2];
				a[2] = a[4], a[4] = a[8], a[8] = a[6], a[6] = fl;

			}

		}
		else if (op[i][0] == 'U'){
			if (op[i][1] == '\''){
				int fl;
				fl = a[2];
				a[2] = a[1], a[1] = a[5], a[5] = a[6], a[6] = fl;

			}
			else if (op[i][1] == '2'){
				int fl;
				fl = a[2];
				a[2] = a[1], a[1] = a[5], a[5] = a[6], a[6] = fl;
				fl = a[2];
				a[2] = a[1], a[1] = a[5], a[5] = a[6], a[6] = fl;

			}
			else{
				int fl;
				fl = a[2];
				a[2] = a[6], a[6] = a[5], a[5] = a[1], a[1] = fl;
			}
		}
		else if (op[i][0] == 'F'){
			if (op[i][1] == '\''){
				int fl;
				fl = a[2];
				a[2] = a[4], a[4] = a[3], a[3] = a[1], a[1] = fl;

			}
			else if (op[i][1] == '2'){
				int fl;
				fl = a[2];
				a[2] = a[4], a[4] = a[3], a[3] = a[1], a[1] = fl;
				fl = a[2];
				a[2] = a[4], a[4] = a[3], a[3] = a[1], a[1] = fl;

			}
			else{
				int fl;
				fl = a[2];
				a[2] = a[1], a[1] = a[3], a[3] = a[4], a[4] = fl;

			}
		}
		else if (op[i][0] == 'L'){
			if (op[i][1] == '\''){
				int fl;
				fl = a[1];
				a[1] = a[3], a[3] = a[7], a[7] = a[5], a[5] = fl;

			}
			else if (op[i][1] == '2'){
				int fl;
				fl = a[1];
				a[1] = a[3], a[3] = a[7], a[7] = a[5], a[5] = fl;
				fl = a[1];
				a[1] = a[3], a[3] = a[7], a[7] = a[5], a[5] = fl;

			}
			else{
				int fl;
				fl = a[1];
				a[1] = a[5], a[5] = a[7], a[7] = a[3], a[3] = fl;
			}
		}
		else if (op[i][0] == 'D'){
			if (op[i][1] == '\''){
				int fl;
				fl = a[3];
				a[3] = a[4], a[4] = a[8], a[8] = a[7], a[7] = fl;
			}
			else if (op[i][1] == '2'){
				int fl;
				fl = a[3];
				a[3] = a[4], a[4] = a[8], a[8] = a[7], a[7] = fl;
				fl = a[3];
				a[3] = a[4], a[4] = a[8], a[8] = a[7], a[7] = fl;
			}
			else{
				int fl;
				fl = a[3];
				a[3] = a[7], a[7] = a[8], a[8] = a[4], a[4] = fl;
			}
		}
		else if (op[i][0] == 'B'){
			if (op[i][1] == '\''){
				int fl;
				fl = a[5];
				a[5] = a[7], a[7] = a[8], a[8] = a[6], a[6] = fl;
			}
			else if (op[i][1] == '2'){
				int fl;
				fl = a[5];
				a[5] = a[7], a[7] = a[8], a[8] = a[6], a[6] = fl;
				fl = a[5];
				a[5] = a[7], a[7] = a[8], a[8] = a[6], a[6] = fl;
			}
			else{
				int fl;
				fl = a[5];
				a[5] = a[6], a[6] = a[8], a[8] = a[7], a[7] = fl;
			}
		}
	}
	int fl = a[1] - a[2];
	int fll = a[1] - a[3];
	int flll = a[1] - a[5];
	if (a[3] - a[4] == fl&&a[5] - a[6] == fl&&a[7] - a[8] == fl&&a[2] - a[4] == fll&&
		a[5] - a[7] == fll&&a[6] - a[8] == fll&&a[2] - a[6] == flll&&a[3] - a[7] == flll&&a[4] - a[8] == flll){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
}
/*
6
RR'
F2B2
UUU
LDL'D'
R2F'UR'U2R2F'R'U2U'R2U'F2U'R'FR2U'R'URU'R'FU
*/
signed main(){
	int _ = 1;
	cin >> _;
	for (int i = 1; i <= _; i++){
		solve();
	}
	return 0;
}

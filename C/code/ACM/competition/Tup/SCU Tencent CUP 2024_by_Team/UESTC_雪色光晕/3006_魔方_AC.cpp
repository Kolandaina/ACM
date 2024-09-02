#include <bits/stdc++.h>
using namespace std;

const int N=101010;
const int inf=0x3f3f3f3f;

int T,n;
char s[N];
int a[6][4];


inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

void chushihua() {
	for(int i=0;i<6;i++) for(int j=0;j<4;j++) a[i][j] = i;
	
}

void RR(int cl) {
//	cout<<"R"<<cl<<endl;
	if(!cl) {
		int tmp1 = a[0][1], tmp2 = a[0][3];
		a[0][1] = a[2][1]; a[0][3] = a[2][3];
		a[2][1] = a[3][1]; a[2][3] = a[3][3];
		a[3][1] = a[1][1]; a[3][3] = a[1][3];
		a[1][1] = tmp1;    a[1][3] = tmp2;
		int tmp3 = a[5][0];
		a[5][0] = a[5][2];
		a[5][2] = a[5][3];
		a[5][3] = a[5][1];
		a[5][1] = tmp3;
	}
	else {
		int tmp1 = a[0][1], tmp2 = a[0][3];
		a[0][1] = a[1][1]; a[0][3] = a[1][3];
		a[1][1] = a[3][1]; a[1][3] = a[3][3];
		a[3][1] = a[2][1]; a[3][3] = a[2][3];
		a[2][1] = tmp1;    a[2][3] = tmp2;
		int tmp3 = a[5][0];
		a[5][0] = a[5][1];
		a[5][1] = a[5][3];
		a[5][3] = a[5][2];
		a[5][2] = tmp3;
	}
}

void UU(int cl) {
//	cout<<"U"<<cl<<endl;
	if(!cl) {
		int tmp1 = a[2][0], tmp2 = a[2][1];
		a[2][0] = a[5][0]; a[2][1] = a[5][1];
		a[5][0] = a[1][3]; a[5][1] = a[1][2];
		a[1][3] = a[4][0]; a[1][2] = a[4][1];
		a[4][0] = tmp1;    a[4][1] = tmp2;
		int tmp3 = a[0][0];
		a[0][0] = a[0][2];
		a[0][2] = a[0][3];
		a[0][3] = a[0][1];
		a[0][1] = tmp3;
	}
	else {
		int tmp1 = a[2][0], tmp2 = a[2][1];
		a[2][0] = a[4][0]; a[2][1] = a[4][1];
		a[4][0] = a[1][3]; a[4][1] = a[1][2];
		a[1][3] = a[5][0]; a[1][2] = a[5][1];
		a[5][0] = tmp1;    a[5][1] = tmp2;
		int tmp3 = a[0][0];
		a[0][0] = a[0][1];
		a[0][1] = a[0][3];
		a[0][3] = a[0][2];
		a[0][2] = tmp3;
	}
}

void FF(int cl) {
//	cout<<"F"<<cl<<endl;
	if(!cl) {
		int tmp1 = a[0][2], tmp2 = a[0][3];
		a[0][2] = a[4][3]; a[0][3] = a[4][1];
		a[4][3] = a[3][1]; a[4][1] = a[3][0];
		a[3][1] = a[5][0]; a[3][0] = a[5][2];
		a[5][0] = tmp1;    a[5][2] = tmp2;
		int tmp3 = a[2][0];
		a[2][0] = a[2][2];
		a[2][2] = a[2][3];
		a[2][3] = a[2][1];
		a[2][1] = tmp3;
	}
	else {
		int tmp1 = a[0][2], tmp2 = a[0][3];
		a[0][2] = a[5][0]; a[0][3] = a[5][2];
		a[5][0] = a[3][1]; a[5][2] = a[3][0];
		a[3][1] = a[4][3]; a[3][0] = a[4][1];
		a[4][3] = tmp1;    a[4][1] = tmp2;
		int tmp3 = a[2][0];
		a[2][0] = a[2][1];
		a[2][1] = a[2][3];
		a[2][3] = a[2][2];
		a[2][2] = tmp3;
	}
}

void LL(int cl) {
//	cout<<"L"<<cl<<endl;
	if(!cl) {
		int tmp1 = a[1][0], tmp2 = a[1][2];
		a[1][0] = a[3][0]; a[1][2] = a[3][2];
		a[3][0] = a[2][0]; a[3][2] = a[2][2];
		a[2][0] = a[0][0]; a[2][2] = a[0][2];
		a[0][0] = tmp1;    a[0][2] = tmp2;
		int tmp3 = a[4][0];
		a[4][0] = a[4][2];
		a[4][2] = a[4][3];
		a[4][3] = a[4][1];
		a[4][1] = tmp3;
	}
	else {
		int tmp1 = a[1][0], tmp2 = a[1][2];
		a[1][0] = a[0][0]; a[1][2] = a[0][2];
		a[0][0] = a[2][0]; a[0][2] = a[2][2];
		a[2][0] = a[3][0]; a[2][2] = a[3][2];
		a[3][0] = tmp1;    a[3][2] = tmp2;
		int tmp3 = a[4][0];
		a[4][0] = a[4][1];
		a[4][1] = a[4][3];
		a[4][3] = a[4][2];
		a[4][2] = tmp3;
	}
}

void BB(int cl) {
//	cout<<"B"<<cl<<endl;
	if(!cl) {
		int tmp1 = a[0][0], tmp2 = a[0][1];
		a[0][0] = a[5][1]; a[0][1] = a[5][3];
		a[5][1] = a[3][3]; a[5][3] = a[3][2];
		a[3][3] = a[4][2]; a[3][2] = a[4][0];
		a[4][2] = tmp1;    a[4][0] = tmp2;
		int tmp3 = a[1][0];
		a[1][0] = a[1][2];
		a[1][2] = a[1][3];
		a[1][3] = a[1][1];
		a[1][1] = tmp3;
	}
	else {
		int tmp1 = a[0][0], tmp2 = a[0][1];
		a[0][0] = a[4][2]; a[0][1] = a[4][0];
		a[4][2] = a[3][3]; a[4][0] = a[3][2];
		a[3][3] = a[5][1]; a[3][2] = a[5][3];
		a[5][1] = tmp1;    a[5][3] = tmp2;
		int tmp3 = a[1][0];
		a[1][0] = a[1][1];
		a[1][1] = a[1][3];
		a[1][3] = a[1][2];
		a[1][2] = tmp3;
	}
}

void DD(int cl) {
//	cout<<"D"<<cl<<endl;
	if(!cl) {
		int tmp1 = a[2][2], tmp2 = a[2][3];
		a[2][2] = a[4][2]; a[2][3] = a[4][3];
		a[4][2] = a[1][1]; a[4][3] = a[1][0];
		a[1][1] = a[5][2]; a[1][0] = a[5][3];
		a[5][2] = tmp1;    a[5][3] = tmp2;
		int tmp3 = a[3][0];
		a[3][0] = a[3][2];
		a[3][2] = a[3][3];
		a[3][3] = a[3][1];
		a[3][1] = tmp3;
	}
	else {
		int tmp1 = a[2][2], tmp2 = a[2][3];
		a[2][2] = a[5][2]; a[2][3] = a[5][3];
		a[5][2] = a[1][1]; a[5][3] = a[1][0];
		a[1][1] = a[4][2]; a[1][0] = a[4][3];
		a[4][2] = tmp1;    a[4][3] = tmp2; 
		int tmp3 = a[3][0];
		a[3][0] = a[3][1];
		a[3][1] = a[3][3];
		a[3][3] = a[3][2];
		a[3][2] = tmp3;
	}
}

int main() {
	T = read();
	while(T--) {
		chushihua();
		scanf("%s",s+1); n = strlen(s+1);
		for(int i=1;i<=n;i++) {
			if(s[i]=='2') {
				if(s[i-1]=='R') RR(0);
				if(s[i-1]=='U') UU(0);
				if(s[i-1]=='F') FF(0);
				if(s[i-1]=='L') LL(0);
				if(s[i-1]=='B') BB(0);
				if(s[i-1]=='D') DD(0);
			}
			if(s[i]=='R' && s[i+1]=='\'') { RR(1); i++; continue; }
			if(s[i]=='R' && s[i+1]!='\'') { RR(0);      continue; }
			if(s[i]=='U' && s[i+1]=='\'') { UU(1); i++; continue; }
			if(s[i]=='U' && s[i+1]!='\'') { UU(0);      continue; }
			if(s[i]=='F' && s[i+1]=='\'') { FF(1); i++; continue; }
			if(s[i]=='F' && s[i+1]!='\'') { FF(0);      continue; }
			if(s[i]=='L' && s[i+1]=='\'') { LL(1); i++; continue; }
			if(s[i]=='L' && s[i+1]!='\'') { LL(0);      continue; }
			if(s[i]=='B' && s[i+1]=='\'') { BB(1); i++; continue; }
			if(s[i]=='B' && s[i+1]!='\'') { BB(0);      continue; }
			if(s[i]=='D' && s[i+1]=='\'') { DD(1); i++; continue; }
			if(s[i]=='D' && s[i+1]!='\'') { DD(0);      continue; }
		}
		bool flag = 1;
		for(int i=0;i<6;i++) {
//			for(int j=0;j<4;j++) cout<<a[i][j]<<" \n"[j==3];
			for(int j=1;j<4;j++) {
				if(a[i][j] != a[i][0]) flag = 0;
			}
		}
		if(flag) cout<<"YES\n";
		else     cout<<"NO\n";
	}
	
	return 0;
}
/*

5
RR'
F2B2
UUU
LDL'D'
R2F'UR'U2R2F'R'U2U'R2U'F2U'R'FR2U'R'URU'R'FU

*/


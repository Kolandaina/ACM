#include <cstdio>
#include <cstring>

using namespace std;

const int N=1e4+10;
char a[24],b[24];
char s[N];

void shift(int a1,int a2,int a3,int a4){
	b[a2]=a[a1];
	b[a3]=a[a2];
	b[a4]=a[a3];
	b[a1]=a[a4];
	
	a[a1]=b[a1];
	a[a2]=b[a2];
	a[a3]=b[a3];
	a[a4]=b[a4];
}

void shift(int a1,int a2,int a3,int a4,int a5,int a6, int a7,int a8){
	b[a3]=a[a1];
	b[a4]=a[a2];
	b[a5]=a[a3];
	b[a6]=a[a4];
	b[a7]=a[a5];
	b[a8]=a[a6];
	b[a1]=a[a7];
	b[a2]=a[a8];
	
	a[a1]=b[a1];
	a[a2]=b[a2];
	a[a3]=b[a3];
	a[a4]=b[a4];
	a[a5]=b[a5];
	a[a6]=b[a6];
	a[a7]=b[a7];
	a[a8]=b[a8];
}

void R() {
//	puts("R");
	shift(8,9,11,10);
	shift(7,5,23,21,12,14,3,1);
}

void U() {
//	puts("U");
	shift(20,21,23,22);
	shift(5,4,17,16,13,12,9,8);
}

void F() {
//	puts("F");
	shift(4,5,7,6);
	shift(22,23,8,10,1,0,19,17);
}

void Ri() {
//	puts("Ri");
	shift(10,11,9,8);
	shift(1,3,14,12,21,23,5,7);
}

void Ui() {
//	puts("Ui");
	shift(22,23,21,20);
	shift(8,9,12,13,16,17,4,5);
}

void Fi() {
//	puts("Fi");
	shift(6,7,5,4);
	shift(17,19,0,1,10,8,23,22);
}

void L() {
	shift(16,17,19,18);
	shift(20,22,4,6,0,2,15,13);
}

void B() {
//	puts("B");
	shift(12,13,15,14);
	shift(21,20,16,18,2,3,11,9);
}

void D() {
	shift(0,1,3,2);
	shift(6,7,10,11,14,15,18,19);
}

void Li() {
	shift(18,19,17,16);
	shift(13,15,2,0,6,4,22,20);
}

void Bi() {
	shift(14,15,13,12);
	shift(9,11,3,2,18,16,20,21);
}

void Di() {
	shift(2,3,1,0);
	shift(19,18,15,14,11,10,7,6);
}

bool check() {
	for (int i=0;i<6;++i){
		for (int j=1;j<4;++j) {
			if (a[i*4+j]!=a[i*4]) {
				return false;
			}
		}
	}
	return true;
}

void clear() {
	for (int i=0;i<6;++i){
		for (int j=0;j<4;++j) {
			a[i*4+j]=i;
		}
	}
}

int main() {
	int T;
	scanf("%d",&T);
	while (T--) {
		scanf("%s",s);
		int len = strlen(s);
		clear();
		for (int i=0;i<len;++i) {
			if (s[i]=='R') {
				if (s[i+1]==39) Ri(),++i;
				else if (s[i+1]=='2') R(),R(),++i;
				else R();
			} else if (s[i]=='U') {
				if (s[i+1]==39) Ui(),++i;
				else if (s[i+1]=='2') U(),U(),++i;
				else U();
			} else if (s[i]=='F') {
				if (s[i+1]==39) Fi(),++i;
				else if (s[i+1]=='2') F(),F(),++i;
				else F();
			} else if (s[i]=='L') {
				if (s[i+1]==39) Li(),++i;
				else if (s[i+1]=='2') L(),L(),++i;
				else L();
			} else if (s[i]=='B') {
				if (s[i+1]==39) Bi(),++i;
				else if (s[i+1]=='2') B(),B(),++i;
				else B();
			} else if (s[i]=='D') {
				if (s[i+1]==39) Di(),++i;
				else if (s[i+1]=='2') D(),D(),++i;
				else D();
			}
//			for (int i=0;i<24;++i)printf("%d",a[i]);
//			putchar('\n');
		}
		printf("%s\n", check() ? "YES" : "NO");
	}
	return 0;
}


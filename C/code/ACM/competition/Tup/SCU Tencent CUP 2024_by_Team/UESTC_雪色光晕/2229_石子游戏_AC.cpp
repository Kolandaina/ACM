#include <bits/stdc++.h>
using namespace std;

const int N=101010;
const int inf=0x3f3f3f3f;

int T;
int n;
int sg[N];

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

int main() {
	T = read();
	while(T--) {
		n = read();
		if(n==1 || n==3 || n==4) { cout<<"Alice\n"; continue; }
		if(n==2) { cout<<"Bob\n"; continue; }
		if(n&1) { cout<<"Bob\n"; continue; }
		else { cout<<"Alice\n"; continue; }
	}
	
	return 0;
}

#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e4+10;;

int n, m1, m2, m3;
int a[30], b[30];
char s[N];

void init()
{
	for(int i=1;i<=24;i++) a[i] = i;
}

void right() {
	for(int i=1;i<=30;i++) b[i] = a[i];
	int t1 = a[10], t2 = a[12];
	std::swap(a[2], t1), std::swap(a[4],t2);
	std::swap(a[22],t1), std::swap(a[24],t2);
	std::swap(a[18],t1), std::swap(a[20],t2);
	std::swap(a[10],t1), std::swap(a[12],t2);
	
	t1 = a[13], t2 = a[15];
	a[14] = b[13], a[13] = b[15];
	a[16] = b[14], a[14] = b[13];
	a[15] = b[16], a[16] = b[14];
	a[13] = b[15], a[15] = b[16];
}

void up() {
	for(int i=1;i<=30;i++) b[i] = a[i];
	int t1 = a[9], t2 = a[10];
	std::swap(a[5], t1), std::swap(a[6],t2);
	std::swap(a[24],t1), std::swap(a[23],t2);
	std::swap(a[13],t1), std::swap(a[14],t2);
	std::swap(a[9],t1), std::swap(a[10],t2);
	
	t1 = a[3], t2 = a[4];
	a[1] = b[3], a[3] = b[4];
	a[2] = b[1], a[1] = b[3];
	a[4] = b[2], a[2] = b[1];
	a[3] = b[4], a[4] = b[2];
}

void front() {
	for(int i=1;i<=30;i++) b[i] = a[i];
	int t1 = a[3], t2 = a[4];
	std::swap(a[13], t1), std::swap(a[15],t2);
	std::swap(a[18],t1), std::swap(a[17],t2);
	std::swap(a[8],t1), std::swap(a[6],t2);
	std::swap(a[3],t1), std::swap(a[4],t2);
	
	t1 = a[9], t2 = a[10];
	a[10] = b[9], a[12] = b[10];
	a[12] = b[10], a[11] = b[12];
	a[11] = b[12], a[9] = b[11];
	a[9] = b[11], a[10] = b[9];
}



bool check() {
	for(int i=1;i<=24;i+=4) {
		int mn = 24, mx = 0;
		for(int j=i;j<i+4;j++) {
			mn = std::min(a[j], mn);
			mx = std::max(a[j], mx);
		}
		if(mx-mn!=3&&mx%4==0) return false;
	}
	return true;
}

void solve()
{
	init();
	
	std::cin >> (s+1);
	n = strlen(s+1);
	for(int i=1;i<=n;i++) {
		if(s[i]=='R'&&s[i+1]=='2') right(), right(), i ++;
		else if(s[i]=='R'&&s[i+1]==39) right(), right(), right(), i ++;
		else if(s[i]=='R') right();
		
		else if(s[i]=='L'&&s[i+1]=='2') right(), right(), i ++;
		else if(s[i]=='L'&&s[i+1]==39) right(), right(), right(), i ++;
		else if(s[i]=='L') right();
		
		else if(s[i]=='U'&&s[i+1]=='2') up(), up(), i ++;
		else if(s[i]=='U'&&s[i+1]==39) up(), up(), up(), i ++;
		else if(s[i]=='U') up();
		
		else if(s[i]=='D'&&s[i+1]=='2') up(), up(), i ++;
		else if(s[i]=='D'&&s[i+1]==39) up(), up(), up(), i ++;
		else if(s[i]=='D') up();
		
		else if(s[i]=='F'&&s[i+1]=='2') front(), front(), i ++;
		else if(s[i]=='F'&&s[i+1]==39) front(), front(), front(), i ++;
		else if(s[i]=='F') front();
		
		else if(s[i]=='B'&&s[i+1]=='2') front(), front(), i ++;
		else if(s[i]=='B'&&s[i+1]==39) front(), front(), front(), i ++;
		else if(s[i]=='B') front();
		
	}
	
	if(check()) std::cout << "YES\n";
	else std::cout << "NO\n";
	
}

signed main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	
	int t = 1;
	std::cin >> t;
	for(int i=1;i<=t;i++)
		solve();
	return 0;
}

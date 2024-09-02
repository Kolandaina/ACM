#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
int mo[7][5];

void init(){
	for(int i=1;i<7;i++)
		for(int j=1;j<5;j++)
			mo[i][j]=i;
}
bool check(){
	for(int i=1;i<7;i++)
		for(int j=1;j<5;j++)
			if(mo[i][j]!=mo[i][1]) return false;
	return true;
}

void R(){
	int t1=mo[1][2],t2=mo[1][3];
	mo[1][2]=mo[2][2];mo[1][3]=mo[2][3];
	mo[2][2]=mo[3][2];mo[2][3]=mo[3][3];
	mo[3][2]=mo[4][2];mo[3][3]=mo[4][3];
	mo[4][2]=t1;mo[4][3]=t2;
	t1=mo[5][4];
	for(int i=4;i>1;i--) mo[5][i]=mo[5][i-1];
	mo[5][1]=t1;
}

void L(){
	int t1=mo[1][1],t2=mo[1][4];
	mo[1][1]=mo[4][1];mo[1][4]=mo[4][4];
	mo[4][1]=mo[3][1];mo[4][4]=mo[3][4];
	mo[3][1]=mo[2][1];mo[3][4]=mo[2][4];
	mo[2][1]=t1;mo[2][4]=t2;
	t1=mo[6][4];
	for(int i=4;i>1;i--) mo[5][i]=mo[5][i-1];
	mo[6][1]=t1;
}

void U(){
	int t1=mo[1][1],t2=mo[1][2];
	mo[1][1]=mo[5][1];mo[1][2]=mo[5][2];
	mo[5][1]=mo[3][1];mo[5][2]=mo[3][2];
	mo[3][1]=mo[6][1];mo[3][2]=mo[6][2];
	mo[6][1]=t1;mo[6][2]=t2;
	t1=mo[4][4];
	for(int i=4;i>1;i--) mo[4][i]=mo[4][i-1];
	mo[4][1]=t1;
}

void D(){
	int t1=mo[1][3],t2=mo[1][4];
	mo[1][3]=mo[6][3];mo[1][4]=mo[6][4];
	mo[6][3]=mo[3][3];mo[6][4]=mo[3][4];
	mo[3][3]=mo[5][3];mo[3][4]=mo[5][4];
	mo[5][3]=t1;mo[5][4]=t2;
	t1=mo[2][4];
	for(int i=4;i>1;i--) mo[2][i]=mo[2][i-1];
	mo[2][1]=t1;
}

void F(){
	int t1=mo[4][3],t2=mo[4][4];
	mo[4][3]=mo[6][2];mo[4][4]=mo[6][3];
	mo[6][2]=mo[2][1];mo[6][3]=mo[2][2];
	mo[2][1]=mo[5][4];mo[2][2]=mo[5][1];
	mo[5][4]=t1;mo[5][1]=t2;
	t1=mo[1][4];
	for(int i=4;i>1;i--) mo[1][i]=mo[1][i-1];
	mo[1][1]=t1;
}

void B(){
	int t1=mo[4][1],t2=mo[4][2];
	mo[4][1]=mo[5][2];mo[4][2]=mo[5][3];
	mo[5][2]=mo[2][3];mo[5][3]=mo[2][4];
	mo[2][3]=mo[6][4];mo[2][4]=mo[6][1];
	mo[6][4]=t1;mo[6][1]=t2;
	t1=mo[3][4];
	for(int i=4;i>1;i--) mo[3][i]=mo[3][i-1];
	mo[3][1]=t1;
}

void print(){
//	for(int i=1;i<7;i++){
//		for(int j=1;j<5;j++)
//			cout<<mo[i][j];
//		cout<<endl;
//	}
//	cout<<endl;
}

void solve(){
	string s;
	init();
	cin>>s;
	int n = s.size();
	int cs = 1;
	char cz=' ';
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(s[i]==39){
			cs*=3;
		}
		else if(s[i]>='0'&&s[i]<='9'){
			cnt *= 10;
			cnt += s[i] - '0';
		}
		else{
			if(cnt==0)cnt=1;
			cs = cs * cnt;
			cs%=4;
//			cout<<cz<<' '<<cs<<endl;
			if(cz == 'R') {
				for(int i = 1; i<=cs;i++) R();
			}
			if(cz == 'F') {
				for(int i = 1; i<=cs;i++) F();
			}
			if(cz == 'U') {
				for(int i = 1; i<=cs;i++) U();
			}
			if(cz == 'B') {
				for(int i = 1; i<=cs;i++) B();
			}
			if(cz == 'L') {
				for(int i = 1; i<=cs;i++) L();
			}
			if(cz == 'D') {
				for(int i = 1; i<=cs;i++) D();
			}
			cnt = 0;
			cs = 1;
			cz = s[i];
//			print();
		}
		
	}
	if(cnt==0)cnt=1;
	cs = cs * cnt;
	cs%=4;
//	cout<<cz<<' '<<cs<<endl;
	if(cz == 'R') {
				for(int i = 1; i<=cs;i++) R();
			}
			if(cz == 'F') {
				for(int i = 1; i<=cs;i++) F();
			}
			if(cz == 'U') {
				for(int i = 1; i<=cs;i++) U();
			}
			if(cz == 'B') {
				for(int i = 1; i<=cs;i++) B();
			}
			if(cz == 'L') {
				for(int i = 1; i<=cs;i++) L();
			}
			if(cz == 'D') {
				for(int i = 1; i<=cs;i++) D();
			}

//	print();
	if(check()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}

signed main(){
	int _=1;
	cin>>_;
	while(_--) solve();
	return 0;
}

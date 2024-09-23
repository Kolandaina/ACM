#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int a[7][5];
int b[7][5];

void cpy1(){
	for(int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			b[i][j]=a[i][j];
		}
	}
}
void cpy2(){
	for(int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			a[i][j]=b[i][j];
		}
	}
}
bool check(){
	for(int i=1;i<7;i++){
		int x=a[i][1];
		for(int j=2;j<5;j++){
			if(a[i][j]!=x){

				return 0;
			}
		}
	}
	return 1;
}

void R(){
	cpy1();
	b[5][2]=a[2][2];
	b[5][4]=a[2][4];
	b[2][2]=a[6][2];
	b[2][4]=a[6][4];
	b[6][2]=a[4][3];
	b[6][4]=a[4][1];
	b[4][3]=a[5][2];
	b[4][1]=a[5][4];
	
	b[3][1]=a[3][3];
	b[3][2]=a[3][1];
	b[3][3]=a[3][4];
	b[3][4]=a[3][2];
	cpy2();
}

void L(){
	cpy1();
	b[5][1]=a[4][4];
	b[5][3]=a[4][2];
	b[4][4]=a[6][1];
	b[4][2]=a[6][3];
	b[6][1]=a[2][1];
	b[6][3]=a[2][3];
	b[2][1]=a[5][1];
	b[2][3]=a[5][3];
	
	b[1][1]=a[1][3];
	b[1][2]=a[1][1];
	b[1][3]=a[1][4];
	b[1][4]=a[1][2];
	cpy2();
}

void U(){
	cpy1();
	b[2][1]=a[3][1];
	b[2][2]=a[3][2];
	b[3][1]=a[4][1];
	b[3][2]=a[4][2];
	b[4][1]=a[1][1];
	b[4][2]=a[1][2];
	b[1][1]=a[2][1];
	b[1][2]=a[2][2];
	
	b[5][1]=a[5][3];
	b[5][2]=a[5][1];
	b[5][3]=a[5][4];
	b[5][4]=a[5][2];
	cpy2();
}

void D(){
	cpy1();
	b[2][3]=a[1][3];
	b[2][4]=a[1][4];
	b[1][3]=a[4][3];
	b[1][4]=a[4][4];
	b[4][3]=a[3][3];
	b[4][4]=a[3][4];
	b[3][3]=a[2][3];
	b[3][4]=a[2][4];
	
	b[6][1]=a[6][3];
	b[6][2]=a[6][1];
	b[6][3]=a[6][4];
	b[6][4]=a[6][2];
	cpy2();
}

void F(){
	cpy1();
	b[5][3]=a[1][4];
	b[5][4]=a[1][2];
	b[1][4]=a[6][2];
	b[1][2]=a[6][1];
	b[6][2]=a[3][1];
	b[6][1]=a[3][3];
	b[3][1]=a[5][3];
	b[3][3]=a[5][4];
	
	b[2][1]=a[2][3];
	b[2][2]=a[2][1];
	b[2][3]=a[2][4];
	b[2][4]=a[2][2];
	cpy2();
}

void B(){
	cpy1();
	b[5][1]=a[3][2];
	b[5][2]=a[3][4];
	b[3][2]=a[6][4];
	b[3][4]=a[6][3];
	b[6][4]=a[1][3];
	b[6][3]=a[1][1];
	b[1][3]=a[5][1];
	b[1][1]=a[5][2];
	
	b[4][1]=a[4][3];
	b[4][2]=a[4][1];
	b[4][3]=a[4][4];
	b[4][4]=a[4][2];
	cpy2();
}

void execu(char c){
	if(c=='R') R();
	else if(c=='U') U();
	else if(c=='F') F();
	else if(c=='D') D();
	else if(c=='L') L();
	else if(c=='B') B();
}


void solve(){
	for(int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			a[i][j]=i;
		}
	}
		
	string s;
	cin >> s;
	
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(c=='2') {execu(s[i-1]);}
		else if(c==39) {execu(s[i-1]);execu(s[i-1]);}
		else if(c=='R' || c=='U' || c=='F' || c=='D' || c=='L' || c=='B') execu(c);
		
	}
	if(check()) cout << "YES\n";
	else cout << "NO\n";
}

void test(){
	for(int i=0;i<7;i++){
		for(int j=0;j<5;j++){
			a[i][j]=i;
		}
	}

	F();
	F();
	B();
	B();
	for(int x=1;x<7;x++){
		for(int y=1;y<5;y++){
			cout << a[x][y]<< " " ;
		}
		cout << endl;
	}
}

int main(){
	ios::sync_with_stdio(false);
	//test();
	int T=1;
	cin>>T;
	while(T--)solve();
}

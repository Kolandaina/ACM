#include<bits/stdc++.h>
using namespace std;

int t,s[7][3][3];
string str;

void rotate1(int x){
	int t1 = s[x][1][1],t2 = s[x][1][2],t3 = s[x][2][1],t4 = s[x][2][2];
	s[x][1][1] = t3;
	s[x][2][1] = t4;
	s[x][1][2] = t1;
	s[x][2][2] = t2;
}

void rotate2(int x){
	int t1 = s[x][1][1],t2 = s[x][1][2],t3 = s[x][2][1],t4 = s[x][2][2];
	s[x][1][1] = t2;
	s[x][2][1] = t1;
	s[x][1][2] = t4;
	s[x][2][2] = t3;
}

void right(){
	int t1 = s[4][1][2],t2 = s[4][2][2];
	for(int i = 1;i<=4;i++){
		int t3 = s[i][1][2],t4 = s[i][2][2];
		s[i][1][2] = t1;
		s[i][2][2] = t2;
		t1 = t3;
		t2 = t4;
	}
	rotate1(6);
}

void left(){
	int t1 = s[4][1][1],t2 = s[4][2][1];
	for(int i = 1;i<=4;i++){
		int t3 = s[i][1][1],t4 = s[i][2][1];
		s[i][1][1] = t1;
		s[i][2][1] = t2;
		t1 = t3;
		t2 = t4;
	}
	rotate2(5);
}

void up(){
	int t1 = s[1][1][1],t2 = s[1][1][2];
	int t3 = s[5][1][1],t4 = s[5][1][2];
	int t5 = s[3][1][1],t6 = s[3][1][2];
	int t7 = s[6][1][1],t8 = s[6][1][2];
	s[1][1][1] = t7;
	s[1][1][2] = t8;
	s[5][1][1] = t1;
	s[5][1][2] = t2;
	s[3][1][1] = t3;
	s[3][1][2] = t4;
	s[6][1][1] = t5;
	s[6][1][2] = t6;
	rotate1(2);
}

void down(){
	int t1 = s[1][2][1],t2 = s[1][2][2];
	int t3 = s[5][2][1],t4 = s[5][2][2];
	int t5 = s[3][2][1],t6 = s[3][2][2];
	int t7 = s[6][2][1],t8 = s[6][2][2];
	s[1][2][1] = t7;
	s[1][2][2] = t8;
	s[5][2][1] = t1;
	s[5][2][2] = t2;
	s[3][2][1] = t3;
	s[3][2][2] = t4;
	s[6][2][1] = t5;
	s[6][2][2] = t6;
	rotate2(4);
}

void front(){
	int t1 = s[2][2][1],t2 = s[2][2][2];
	int t3 = s[6][2][1],t4 = s[6][2][2];
	int t5 = s[4][2][1],t6 = s[4][2][2];
	int t7 = s[5][2][1],t8 = s[5][2][2];
	s[2][2][1] = t7;
	s[2][2][2] = t8;
	s[6][2][1] = t1;
	s[6][2][2] = t2;
	s[4][2][1] = t3;
	s[4][2][2] = t4;
	s[5][2][1] = t5;
	s[5][2][2] = t6;
	rotate1(1);
}

void back(){
	int t1 = s[2][1][1],t2 = s[2][1][2];
	int t3 = s[6][1][1],t4 = s[6][1][2];
	int t5 = s[4][1][1],t6 = s[4][1][2];
	int t7 = s[5][1][1],t8 = s[5][1][2];
	s[2][1][1] = t7;
	s[2][1][2] = t8;
	s[6][1][1] = t1;
	s[6][1][2] = t2;
	s[4][1][1] = t3;
	s[4][1][2] = t4;
	s[5][1][1] = t5;
	s[5][1][2] = t6;
	rotate2(3);
}

void init(){
	for(int i = 1;i<=6;i++){
		for(int j = 1;j<=2;j++){
			for(int k = 1;k<=2;k++) s[i][j][k] = i;
		}
	}
}

int main()
{
	cin>>t;
	while(t--){
		init();
		cin>>str;
		for(int i = 0;i<str.size();i++){
			if(str[i]=='R'){
				if(i+1==str.size()) right();
				else if(str[i+1]==39){
					right();
					right();
					right();
					i++;
				}
				else if(str[i+1]=='2'){
					right();
					right();
					i++;
				}
				else right();
			}
			if(str[i]=='L'){
				if(i+1==str.size()) left();
				else if(str[i+1]==39){
					left();
					left();
					left();
					i++;
				}
				else if(str[i+1]=='2'){
					left();
					left();
					i++;
				}
				else left();
			}
			if(str[i]=='U'){
				if(i+1==str.size()) up();
				else if(str[i+1]==39){
					up();
					up();
					up();
					i++;
				}
				else if(str[i+1]=='2'){
					up();
					up();
					i++;
				}
				else up();
			}
			if(str[i]=='D'){
				if(i+1==str.size()) down();
				else if(str[i+1]==39){
					down();
					down();
					down();
					i++;
				}
				else if(str[i+1]=='2'){
					down();
					down();
					i++;
				}
				else down();
			}
			if(str[i]=='F'){
				if(i+1==str.size()) front();
				else if(str[i+1]==39){
					front();
					front();
					front();
					i++;
				}
				else if(str[i+1]=='2'){
					front();
					front();
					i++;
				}
				else front();
			}
			if(str[i]=='B'){
				if(i+1==str.size()) back();
				else if(str[i+1]==39){
					back();
					back();
					back();
					i++;
				}
				else if(str[i+1]=='2'){
					back();
					back();
					i++;
				}
				else back();
			}
		}
		bool flag = true;
		for(int i = 1;i<=6;i++){
			if(!flag) break;
			int t = s[i][1][1];
			for(int j = 1;j<=2;j++){
                if(!flag) break;
                for(int k = 1;k<=2;k++){
                    if(s[i][j][k]!=t){
                        flag = false;
                        break;
                    }
                }
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}

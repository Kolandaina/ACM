#include <bits/stdc++.h>
using namespace std;
int s[25];
int mid;

const int N = 10005;
char in[N];
int ind;

void outs(){
	for(int i = 1; i<= 24; ++i){
		cout << i <<" ";
	}
	cout << endl;
	for(int i = 1; i<= 24; ++i){
		cout << s[i] << " ";
	}
	cout << endl;
	cout << endl;
}
void R(){
	mid = s[15];
	s[15] = s[16];
	s[16] = s[14];
	s[14] = s[13];
	s[13] = mid;
	
	mid = s[4];
	s[4] = s[12];
	s[12] = s[24];
	s[24] = s[17];
	s[17] = mid;
	
	mid = s[19];
	s[19] = s[2];
	s[2] = s[10];
	s[10] = s[22];
	s[22] = mid;
}
void R_(){
	mid = s[13];
	s[13] = s[14];
	s[14] = s[16];
	s[16] = s[15];
	s[15] = mid;
	
	mid = s[4];
	s[4] = s[17];
	s[17] = s[24];
	s[24] = s[12];
	s[12] = mid;
	
	mid = s[2];
	s[2] = s[19];
	s[19] = s[22];
	s[22] = s[10];
	s[10] = mid;
	
}

void L(){
	mid = s[6];
	s[6] = s[8];
	s[8] = s[7];
	s[7] = s[5];
	s[5] = mid;
	
	mid = s[9];
	s[9] = s[21];
	s[21] = s[20];
	s[20] = s[1];
	s[1] = mid;
	
	mid = s[11];
	s[11] = s[3];
	s[3] = s[18];
	s[18] = s[23];
	s[23] = mid;
}
void L_(){
	mid = s[5];
	s[5] = s[7];
	s[7] = s[8];
	s[8] = s[6];
	s[6] = mid;
	
	mid = s[1];
	s[1] = s[20];
	s[20] = s[21];
	s[21] = s[9];
	s[9] = mid;
	
	mid = s[23];
	s[23] = s[18];
	s[18] = s[3];
	s[3] = s[11];
	s[11] = mid;
}

void U(){
	mid = s[3];
	s[3] = s[4];
	s[4] =s[2];
	s[2] = s[1];
	s[1] = mid;
	
	mid = s[6];
	s[6] =s[10];
	s[10] = s[14];
	s[14] = s[18];
	s[18] = mid;
	
	mid = s[5];
	s[5] = s[9];
	s[9] = s[13];
	s[13] = s[17];
	s[17] = mid;
	
}
void U_(){
	mid = s[1];
	s[1] = s[2];
	s[2] = s[4];
	s[4] = s[3];
	s[3] = mid;
	
	mid = s[18];
	s[18] = s[14];
	s[14] = s[10];
	s[10] = s[6];
	s[6] = mid;
	
	mid = s[17];
	s[17] = s[13];
	s[13] = s[9];
	s[9] = s[5];
	s[5] = mid;
}

void D(){
	mid = s[23];
	s[23] = s[24];
	s[24] = s[22];
	s[22] = s[21];
	s[21] = mid;
	
	mid = s[19];
	s[19] = s[15];
	s[15] = s[11];
	s[11] = s[7];
	s[7] = s[19];
	
	mid = s[20];
	s[20] = s[16];
	s[16] = s[12];
	s[12] = s[8];
	s[8] = mid;
}
void D_(){
	mid = s[8];
	s[8] = s[12];
	s[12] = s[16];
	s[16] = s[20];
	s[20] = mid;
	
	mid = s[7];
	s[7] = s[11];
	s[11] = s[15];
	s[15] = s[19];
	s[19] = mid;
	
	mid = s[21];
	s[21] = s[22];
	s[22] = s[24];
	s[24] = s[23];
	s[23] = mid;
}

void B(){
	mid = s[19];
	s[19] = s[20];
	s[20] = s[18];
	s[18] = s[17];
	s[17] = mid;
	
	mid = s[14];
	s[14] = s[24];
	s[24] = s[7];
	s[7] = s[1];
	s[1] = mid;
	
	mid = s[16];
	s[16] = s[23];
	s[23] = s[5];
	s[5] = s[2];
	s[2] = mid;
}

void B_(){
	mid = s[17];
	s[17] = s[18];
	s[18] = s[20];
	s[20] = s[19];
	s[19] = mid;
	
	mid = s[1];
	s[1] = s[7];
	s[7] = s[24];
	s[24] = s[14];
	s[14] = mid;
	
	mid = s[2];
	s[2] = s[5];
	s[5] = s[23];
	s[23] = s[16];
	s[16] = mid;
}

void F(){
	mid = s[11];
	s[11] = s[12];
	s[12] = s[10];
	s[10] = s[9];
	s[9] = mid;
	
	mid = s[3];
	s[3] = s[8];
	s[8] = s[22];
	s[22] = s[13];
	s[13] = mid;
	
	mid = s[4];
	s[4] = s[6];
	s[6] = s[21];
	s[21] = s[15];
	s[15] = mid;
	
}

void F_(){
	mid = s[9];
	s[9] = s[10];
	s[10] = s[12];
	s[12] = s[11];
	s[11] = mid;
	
	mid = s[13];
	s[13] = s[22];
	s[22] = s[8];
	s[8] = s[3];
	s[3] = mid;
	
	mid = s[15];
	s[15] = s[21];
	s[21] = s[6];
	s[6] = s[4];
	s[4] = mid;
}

bool jd(int i){
	int b = i * 4;
	int col = (s[b + 1] - 1) / 4;
	if(col == (s[b + 2] - 1) / 4 && 
	   col == (s[b + 3] - 1) / 4 &&
	   col == (s[b + 4] - 1) / 4 ){
		return true;
	}
	return false;
}

int main(){
	int n; scanf("%d", &n);
	while (n--)
	{
		for(int i=1;i<=24;++i){
			s[i] = i;
		}
		
		scanf("%s", in + 1); int len = strlen(in + 1);
		for (ind = 1;ind <= len; ind++)
		{
			if (in[ind] == 'F')
			{
				if (in[ind + 1] == 39) F_();
				else if (in[ind + 1] == '2') {F(); F();}
				else {F(); ind--;}
				ind++;
			}
			else if (in[ind] == 'B')
			{
				if (in[ind + 1] == 39) B_();
				else if (in[ind + 1] == '2') {B(); B();}
				else {B(); ind--;}
				ind++;
			}
			else if (in[ind] == 'L')
			{
				if (in[ind + 1] == 39) L_();
				else if (in[ind + 1] == '2') {L(); L();}
				else {L(); ind--;}
				ind++;
			}
			else if (in[ind] == 'R')
			{
				if (in[ind + 1] == 39) R_();
				else if (in[ind + 1] == '2') {R(); R();}
				else {R(); ind--;}
				ind++;
			}
			else if (in[ind] == 'U')
			{
				if (in[ind + 1] == 39) U_();
				else if (in[ind + 1] == '2') {U(); U();}
				else {U(); ind--;}
				ind++;
			}
			else if (in[ind] == 'D')
			{
				if (in[ind + 1] == 39) D_();
				else if (in[ind + 1] == '2') {D(); D();}
				else {D(); ind--;}
				ind++;
			}
		}
		bool res = true;
		for(int i = 0;i<=5;++i){
			if(!jd(i)){
				cout << "NO"<< endl;
				res = false;
				break;
			}
		}
		if (res) cout << "YES"<< endl;
	}
	return 0;
	
}

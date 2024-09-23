#include<bits/stdc++.h>
using namespace std;
int T,a[7][5];
void rotate(int (&a)[7][5],char c){
	if(c=='R'){
		int tmp1=a[1][2],tmp2=a[1][4];
		a[1][2]=a[4][4],a[1][4]=a[4][2];
		a[4][2]=a[3][1],a[4][4]=a[3][3];
		a[3][1]=a[2][4],a[3][3]=a[2][2];
		a[2][2]=tmp1,a[2][4]=tmp2;
		int tmp3=a[6][1];
		a[6][1]=a[6][3];
		a[6][3]=a[6][4];
		a[6][4]=a[6][2];
		a[6][2]=tmp3;
	}
	else if(c=='L'){
		int tmp1=a[1][1],tmp2=a[1][3];
		a[1][1]=a[4][3],a[1][3]=a[4][1];
		a[4][3]=a[3][4],a[4][1]=a[3][2];
		a[3][4]=a[2][1],a[3][2]=a[2][3];
		a[2][1]=tmp1,a[2][3]=tmp2;
		
		int tmp3=a[5][1];
		a[5][1]=a[5][2];
		a[5][2]=a[5][4];
		a[5][4]=a[5][3];
		a[5][3]=tmp3;
	}
	else if(c=='U'){
		int tmp1=a[1][1],tmp2=a[1][2];
		a[1][1]=a[6][1],a[1][2]=a[6][2];
		a[6][1]=a[3][1],a[6][2]=a[3][2];
		a[3][1]=a[5][1],a[3][2]=a[5][2];
		a[5][1]=tmp1,a[5][2]=tmp2;
		
		int tmp3=a[2][1];
		a[2][1]=a[2][3];
		a[2][3]=a[2][4];
		a[2][4]=a[2][2];
		a[2][2]=tmp3;
	} 
	else if(c=='D'){
		int tmp1=a[1][3],tmp2=a[1][4];
		a[1][3]=a[6][3],a[1][4]=a[6][4];
		a[6][3]=a[3][3],a[6][4]=a[3][4];
		a[3][3]=a[5][3],a[3][4]=a[5][4];
		a[5][3]=tmp1,a[5][4]=tmp2;
		
		int tmp3=a[4][1];
		a[4][1]=a[4][3];
		a[4][3]=a[4][4];
		a[4][4]=a[4][2];
		a[4][2]=tmp3;
	}
	else if(c=='F'){
		int tmp1=a[2][3],tmp2=a[2][4];
		a[2][3]=a[5][4],a[2][4]=a[5][2];
		a[5][4]=a[4][4],a[5][2]=a[4][3];
		a[4][4]=a[6][1],a[4][3]=a[6][3];
		a[6][1]=tmp1,a[6][3]=tmp2;
		
		int tmp3=a[1][1];
		a[1][1]=a[1][3];
		a[1][3]=a[1][4];
		a[1][4]=a[1][2];
		a[1][2]=tmp3;
	}
	else{
		int tmp1=a[2][1],tmp2=a[2][2];
		a[2][1]=a[5][3],a[2][2]=a[5][1];
		a[5][3]=a[4][2],a[5][1]=a[4][1];
		a[4][2]=a[6][2],a[4][1]=a[6][4];
		a[6][2]=tmp1,a[6][4]=tmp2;
		
		int tmp3=a[3][1];
		a[3][1]=a[3][2];
		a[3][2]=a[3][4];
		a[3][4]=a[3][3];
		a[3][3]=tmp3;
	}
}
bool check(int (&a)[7][5]){
	for(int i=1;i<=6;i++){
		int jdd=a[i][1];
		for(int j=2;j<=4;j++){
			if(a[i][j]!=jdd)return 0;
		}
	}
	return 1;
}
int main(){
	freopen("1.in","r",stdin);
	cin>>T;
	while(T--){
		for(int i=1;i<=6;i++)
			for(int j=1;j<=4;j++)a[i][j]=i;
		string s;
		cin>>s;
		int len=s.size();
		for(int i=0;i<len;i++){
//			cout<<s[i]<<" ";
			if((int)s[i]!=39&&s[i]!='2'){
				if(i+1<len&&((int)s[i+1]==39||s[i+1]=='2')){
					if(s[i+1]=='2'){
						rotate(a,s[i]);
						rotate(a,s[i]);
					}
					else if((int)s[i+1]==39){
						rotate(a,s[i]);
						rotate(a,s[i]);
						rotate(a,s[i]);
					}
				}
				else{
					rotate(a,s[i]);
				}
			}
//			else continue;
//			for(int i=1;i<=6;i++){
//				for(int j=1;j<=4;j++)cout<<a[i][j]<<" ";
//				puts("");
//			}
//			puts("");
		}
		
			
		if(check(a))puts("YES");
		else puts("NO");
	}
	return 0;
}

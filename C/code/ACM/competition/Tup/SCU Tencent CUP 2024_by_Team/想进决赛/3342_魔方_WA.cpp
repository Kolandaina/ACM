#include <iostream>
#include <vector>
using namespace std;
struct NODE{
	int v0;
	int v1;
	int v2;
}H[8];

int T, n;
vector<int> opts;

void rd(){
	opts.clear();
	int ch;
	while ((ch = getchar()) != '\n'){
		if (ch == 'R')
		  opts.push_back(1);
		if (ch == 'F')
		  opts.push_back(3);
		if (ch == 'L')
		  opts.push_back(5);
		if (ch == 'B')
		  opts.push_back(7);
		if (ch == 'U')
		  opts.push_back(9);
		if (ch == 'D')
		  opts.push_back(11);
		if (ch == '2')
		  opts.push_back(opts[opts.size()-1]);
		if (ch == 39)
		  opts[opts.size()-1] += 1;
	}
	n = opts.size();
//	for (int i = 0; i < n; i ++)
//	  printf("%d ",opts[i]);
//	printf("\n");
}
void change(int *a,int *b,int *c,int *d){
	int temp = *d;
	*d=*c;
	*c=*b;
	*b=*a;
	*a=temp;
}
void op1(){
	change(&H[2].v0,&H[1].v0,&H[5].v0,&H[6].v0);
	change(&H[2].v1,&H[1].v1,&H[5].v1,&H[6].v1);
	change(&H[2].v2,&H[1].v2,&H[5].v2,&H[6].v2);	
}
void op2(){
	change(&H[1].v0,&H[2].v0,&H[6].v0,&H[5].v0);
	change(&H[1].v1,&H[2].v1,&H[6].v1,&H[5].v1);
	change(&H[1].v2,&H[2].v2,&H[6].v2,&H[5].v2);
}
void op3(){
	change(&H[0].v0,&H[1].v2,&H[2].v1,&H[3].v2);
	change(&H[0].v2,&H[1].v0,&H[2].v2,&H[3].v1);
	change(&H[0].v1,&H[1].v1,&H[2].v0,&H[3].v0);	
}
void op4(){
	change(&H[0].v0,&H[4].v2,&H[3].v1,&H[2].v2);
	change(&H[0].v2,&H[4].v1,&H[3].v2,&H[2].v0);
	change(&H[0].v1,&H[4].v0,&H[3].v0,&H[2].v1);
}
void op5(){
	change(&H[0].v0,&H[3].v0,&H[7].v0,&H[4].v0);
	change(&H[0].v1,&H[3].v1,&H[7].v1,&H[4].v1);
	change(&H[0].v2,&H[3].v2,&H[7].v2,&H[4].v2);
}
void op6(){
	change(&H[0].v0,&H[4].v0,&H[7].v0,&H[3].v0);
	change(&H[0].v1,&H[4].v1,&H[7].v1,&H[3].v1);
	change(&H[0].v2,&H[4].v2,&H[7].v2,&H[3].v2);
}
void op7(){
	change(&H[4].v0,&H[7].v1,&H[6].v1,&H[5].v0);
	change(&H[4].v1,&H[7].v2,&H[6].v0,&H[5].v2);
	change(&H[4].v2,&H[7].v0,&H[6].v2,&H[5].v1);
}
void op8(){
	change(&H[4].v0,&H[5].v0,&H[6].v1,&H[7].v1);
	change(&H[4].v1,&H[5].v2,&H[6].v0,&H[7].v2);
	change(&H[4].v2,&H[5].v1,&H[6].v2,&H[7].v0);
	
}
void op9(){
	change(&H[0].v0,&H[4].v1,&H[5].v1,&H[1].v0);
	change(&H[0].v1,&H[4].v2,&H[5].v0,&H[1].v2);
	change(&H[0].v2,&H[4].v0,&H[5].v2,&H[1].v1);
}
void op10(){
	change(&H[0].v0,&H[1].v0,&H[5].v1,&H[4].v1);
	change(&H[0].v1,&H[1].v2,&H[5].v0,&H[4].v2);
	change(&H[0].v2,&H[1].v1,&H[5].v2,&H[4].v0);
}
void op11(){
	change(&H[3].v0,&H[2].v2,&H[6].v1,&H[7].v2);
	change(&H[3].v2,&H[2].v0,&H[6].v2,&H[7].v1);
	change(&H[3].v1,&H[2].v1,&H[6].v0,&H[7].v0);
}
void op12(){
	change(&H[3].v0,&H[7].v2,&H[6].v1,&H[2].v2);
	change(&H[3].v1,&H[7].v0,&H[6].v0,&H[2].v1);
	change(&H[3].v2,&H[7].v1,&H[6].v2,&H[2].v0);
}
bool check(){
	if(H[0].v1==H[1].v1&&H[1].v1==H[2].v0&&H[2].v0==H[3].v0&&H[1].v2==H[2].v2&&H[2].v2==H[5].v2&&H[5].v2==H[6].v2&&H[2].v1==H[3].v1&&H[3].v1==H[6].v0&&H[6].v1==H[7].v1){
		return 1;
	}
	else return 0;
	
}
int main(){

	scanf("%d\n",&T);
	while (T --){
		H[2].v0=1;
		H[2].v1=2;
		H[2].v2=3;
		H[0].v0=4;
		H[0].v1=1;
		H[0].v2=5;
		H[1].v0=4;
		H[1].v1=1;
		H[1].v2=3;
		H[3].v0=1;
		H[3].v1=2;
		H[3].v2=5;
		H[4].v0=6;
		H[4].v1=4;
		H[4].v2=5;
		H[5].v0=6;
		H[5].v1=4;
		H[5].v2=3;
		H[6].v0=2;
		H[6].v1=6;
		H[6].v2=3;
		H[7].v0=2;
		H[7].v1=6;
		H[7].v2=5;
		
		rd();
		for(int i = 0;i<n;i++){
			if(opts[i]==1){
				op1();
			}
			if(opts[i]==2){
				op2();
			}
			if(opts[i]==3){
				op3();
			}
			if(opts[i]==4){
				op4();
			}
			if(opts[i]==5){
				op5();
			}
			if(opts[i]==6){
				op6();
			}
			if(opts[i]==7){
				op7();
			}
			if(opts[i]==8){
				op8();
			}
			if(opts[i]==9){
				op9();
			}
			if(opts[i]==10){
				op10();
			}
			if(opts[i]==11){
				op11();
			}
			if(opts[i]==12){
				op12();
			}
			
		}
		if(check())
		printf("YES\n");
		else
		printf("NO\n");
	}
	return 0;
}


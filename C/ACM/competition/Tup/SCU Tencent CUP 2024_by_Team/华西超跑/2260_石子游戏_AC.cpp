#include<stdio.h>
#define N 1000001
int sg[N];
int main(){
	for(int i=1;i<N;i++){
		if((i&1)==1){
			sg[i]=sg[i-1]==0?1:0;
		}else{
			int a=sg[i-1],b=sg[i>>1];
			if(a!=0&&b!=0){
				sg[i]=0;
			}else if(a==0&&b!=1||a!=1&&b==0){
				sg[i]=1;
			}else{
				sg[i]=2;
			}
		}
	}
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int x;
		scanf("%d",&x);
		if(sg[x]==0){
			puts("Bob");
		}else{
			puts("Alice");
		}
	}
	return 0;
}

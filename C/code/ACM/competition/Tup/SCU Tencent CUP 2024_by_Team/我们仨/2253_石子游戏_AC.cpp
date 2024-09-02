#include <iostream>
int rd(){
	int xx=0;char flag=1,ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		xx=xx*10+ch-'0';
		ch=getchar();
	}
	return xx*flag;
}
using namespace std;
int t=0;
int a[1000006];
int main() {
	t=rd();int x=0;
	a[1]=1;
	for(int i=2;i<=1000000;i++){
		if(i%2==0){
			if(a[i/2]==2||a[i-1]==2)a[i]=1;
			else a[i]=2;
		}
		else{
			if(a[i-1]==2)a[i]=1;
			else a[i]=2;
		}
	}
	while(t--){
		x=rd();
		if(a[x]==1)
		printf("Alice\n");
		else printf("Bob\n");
	}
	return 0;
}

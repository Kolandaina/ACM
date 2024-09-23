#include<stdio.h>
#include<string.h>
int main()
{
	int t;
	scanf("%d",&t);
	for(int k=0;k<t;k++){
		char m[1000];
		scanf("%s",&m);
		int n=strlen(m);
		if(n<=10) printf("%s\n",m);
		else{
			printf("%c",m[0]);
			printf("%d",n-2);
			printf("%c",m[n-1]);
			printf("\n");
		}
	}
	return 0;
}
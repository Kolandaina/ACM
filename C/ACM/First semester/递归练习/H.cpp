#include <bits/stdc++.h>
using namespace std;
int a[1001]={1},sum,n;
int f(int s,int t){
	int i,j;
	for(i=a[t-1];i<=s;i++){
		if(i<n){		
			a[t]=i;
			s-=i;
			if(s==0){
				sum++;					
				printf("%d=",n);
				for(j=1;j<=t-1;j++)
					printf("%d+",a[j]);
				printf("%d\n",a[t]);
			}
			else f(s,t+1);
		}
		s+=i;							
	}
}
int main(){
	scanf("%d",&n);
	f(n,1);				
	return 0;
}

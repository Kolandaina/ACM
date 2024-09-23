#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		int tmp=n,num=0;
		while(tmp){
			num++;
			tmp>>=1;
		}
		if((n&1)&&(num&1)){
			puts("Alice");
		}
		else if(n&1){
			puts("Bob");
		}
		else if(num&1){
			puts("Alice");			
		}
		else{
			puts("Bob");
		}
	}
	return 0;
}

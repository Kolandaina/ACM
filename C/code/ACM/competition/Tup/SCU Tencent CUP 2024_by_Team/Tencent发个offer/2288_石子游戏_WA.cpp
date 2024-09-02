#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		int tmp=n;
		if(n&1){
			puts("Alice");
		}
		else{
			puts("Bob");	
		}
	}
	return 0;
}

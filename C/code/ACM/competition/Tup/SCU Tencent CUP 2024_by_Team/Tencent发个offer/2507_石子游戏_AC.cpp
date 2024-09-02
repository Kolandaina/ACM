#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1||n==3)puts("Alice");
		else if(n==2)puts("Bob");
		else if(n&1)puts("Bob");
		else puts("Alice");
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int t,n;

int main(){
	cin>>t;
	while(t--!=0){
		cin>>n;
		if(n==2) cout<<"Bob"<<endl;
		else if(n>=4){
			if(n%2==0) cout<<"Alice"<<endl;
			else if(n%2==1) cout<<"Bob"<<endl;
		}
		else cout<<"Alice"<<endl;
	}
	return 0;
}

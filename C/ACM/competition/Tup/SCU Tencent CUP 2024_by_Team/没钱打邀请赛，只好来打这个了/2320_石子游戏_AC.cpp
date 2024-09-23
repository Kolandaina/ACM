#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		if(n==1||n==3){
			cout<<"Alice\n";
			continue;
		}
		if(n==2){
			cout<<"Bob\n";
			continue;
		}
		if(n%2){
			cout<<"Bob\n";
		}
		else{
			cout<<"Alice\n";
		}
	}
	return 0;
}

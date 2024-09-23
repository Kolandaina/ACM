#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	int m,sum1=0,sum5=0,sum10=0;
	while(k--){
		cin>>m;
		if(m==1){
			sum1++;
		}
		if(m==5){
			sum5++;
		}
		if(m==10){
			sum10++;
		}
	}
	cout<<sum1<<" "<<sum5<<" "<<sum10;
	return 0;
}
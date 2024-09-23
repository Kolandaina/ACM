#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
long long mod = 1e9+7;

int main () {
	int n;
	cin>>n;
	while(n--){
		int q;
		cin>>q;
		if(q==1||q==3) cout<<"Alice"<<endl;
		else if(q==2) cout<<"Bob"<<endl;
		else{
			if(q%2==0) cout<<"Alice"<<endl;
			else cout<<"Bob"<<endl;
		}
	}
	return 0;
}


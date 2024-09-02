#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
string my_to_string(long long s){
	string ans;
	while(s){
		char tt = '0'+s%10;
		ans = ans +tt;
		s/=10;
	}
	reverse(ans.begin(),ans.end());
	return ans;
}
int main(){
	int n,m,k;
	cin>>n>>m>>k;
//	cout<<my_to_string(789456)<<endl;
	int t=0;
	long long a;
	long long s=pow(2,n-1);
	while(s>0){
		s/=10;
		t++;
	}
	if(n!=k||s+2+t>m){
		cout<<-1<<endl;
	}else{
		for(int i=0;i<n;i++){
			s=pow(2,i);
			string k=my_to_string(s);
			string ans="{"+k+"}";
			for(int j=0;j<s;j++){
				ans+=",";
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}

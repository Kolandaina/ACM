#include<bits/stdc++.h>
using namespace std;
int Query(string s){
	cout<<"? "<<s<<endl;
	int x;
	cin>>x;
	return x;
}
int main(){
	srand(time(0));
	int n;
	cin>>n;
	string s,t;
	int ct=0,len;
	while(s.length()<n){
		char c=rand()%2+'0';
		if(Query(s+c)>0){
			s+=c;
			t=s;
			ct=0;
		}else{
			s+=c^1;
			ct++;
			if(ct>7){
				len=t.length();
				for(int i=0;i<ct;i++){
					if(Query(t+s[len+i])>0){
						t+=s[len+i];
					}else{
						goto Stage;
					}
				}
			}
		}
	}
	len=t.length();
	for(int i=0;i<ct;i++){
		if(Query(t+s[len+i])>0){
			t+=s[len+i];
		}else{
			break;
		}
	}
	Stage:;
	s=t;
	int l=s.length();
	for(int i=l;i<n;i++){
		if(Query('0'+s)>0){
			s='0'+s;
		}else{
			s='1'+s;
		}
	}
	cout<<"! "<<s;
	return 0;
}

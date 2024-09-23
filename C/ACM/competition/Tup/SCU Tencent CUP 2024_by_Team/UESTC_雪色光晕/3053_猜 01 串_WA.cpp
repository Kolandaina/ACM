#include <bits/stdc++.h>
using namespace std;

const int N=2e3+7;
const int inf=0x3f3f3f3f;

inline int read() {
	int sum = 0, ff = 1; char c = getchar();
	while(c<'0' || c>'9') { if(c=='-') ff = -1; c = getchar(); }
	while(c>='0'&&c<='9') { sum = sum * 10 + c -'0'; c = getchar(); }
	return sum * ff;
}

int query(const string &X){
	cout<<"? "<<X<<endl;
	cout.flush();
	int x;
	cin>>x;
	return x;
}

int main() {
	int n,x,k=0,p=0;
	bool Tag=0;
	cin>>n;
	string now="";
	while(1){
		int x=query("0"+now);
		if(x){
			now="0"+now;
			k=0;
		}else{
			if((++k)>=100){
				if(query("1"+now)){
					k=0;
					now="1"+now;
				}else{
					while(p<now.length()&&!query("1"+now.substr(p,now.length()-p))) p++;
					if(p!=now.length()) p--; Tag=1; break;
				}
			}else now="1"+now;
		}
	}
	if(p==now.length()) now="";
	else now=now.substr(p,now.length()-p);
	while(now.length()<n){
		if(query(now+"0")) now+="0";
		else now+="1";
	}
	cout<<"! "<<now<<endl;
	cout.flush();
	return 0;
}

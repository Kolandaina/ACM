#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int r=0,f=1;char  c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
	return r*f;
}
inline string sread(){
	string s=" ";char c=getchar();
	while(c<'a'||c>'z')c=getchar();
	while(c<='z'&&c>='a')s+=c,c=getchar();
	return s;
}
int lowbit(int x){return x&(-x);}
string s, ns, emp;
int q(string ns){
	cout<<"? "<<ns<<endl;
	cout.flush();
	int cnt; cin>>cnt;
	return cnt;
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int n;
	cin >> n;
	bool ok = false;
	char op = '1';
	ns += '1';
	if(!q(ns)){
		cout<<"! ";
		for(int i = 1; i <= n; i++) cout<<0;
		cout<<endl;
		return 0;
	}
	ns.clear(); ns += '0';
	if(!q(ns)){
		cout<<"! ";
		for(int i = 1; i <= n; i++) cout<<1;
		cout<<endl;
		return 0;		
	}
	int len1 = 1, len0 = 1;
	ns.clear();
	ns += '1';
	for(int i = 2; ;i++){
		ns += '1';
		if(!q(ns)){
			len1 = i-1; break;
		}
	}
	ns.clear();
	ns += '0';
	for(int i = 2;;i++){
		ns += '0';
		if(!q(ns)){
			len0 = i-1;break;
		}
	}
	ns.clear();
	for(int i = 1; i <= len1; i++) s += '1';
	op = '0';
	while(true){
		ns.clear();
		bool ok = false;
		if(op == '0'){
			for(int i = 1; i <= len0; i++){
				int now = q('0' + ns + s);
				if(!now) break;
				else ns += '0', ok = true;
				if(s.length()+ns.length() >= n) break;
			}	
		}else{
			for(int i = 1; i <= len1; i++){
				int now = q('1' + ns + s);
				if(!now) break;
				else ns += '1', ok = true;
				if(s.length()+ns.length() >= n) break;
			}	
		}
		s = ns + s;
		if(op == '1') op = '0';
		else op = '1';if(s.length() >=n) break;
		if(!ok) break;
	}
	op = '0';
	while(true){
		if(s.length() >=n) break; 
		ns.clear();
		bool ok = false;
		if(op == '0'){
			for(int i = 1; i <= len0; i++){
				int now = q(s + ns + '0');
				if(!now) break;
				else ns += '0', ok = true;
				if(s.length()+ns.length() >= n) break;
			}	
		}else{
			for(int i = 1; i <= len1; i++){
				int now = q(s + ns + '1');
				if(!now) break;
				else ns += '1', ok = true;
				if(s.length()+ns.length() >= n) break;
			}	
		}
		s = s + ns;
		if(op == '1') op = '0';
		else op = '1';
	//	cout<<s.length()<<" "<<s<<endl;
		if(s.length() >= n) break;
		if(!ok) break;
	}
	cout<<"! "<<s<<endl;
	return 0;
}


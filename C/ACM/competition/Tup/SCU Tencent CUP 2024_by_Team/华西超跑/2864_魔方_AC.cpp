#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=std::vector<int>;
using pii=std::pair<int,int>;
#define eb emplace_back
#define all(c) std::begin(c),std::end(c)

constexpr int dpos[6][2]={{2,2},{0,0},{2,0},{2,6},{4,0},{2,4}};
char deb[22][22];
signed main(){
	std::map<char,int>sid;
	sid['R']=0;
	sid['U']=1;
	sid['F']=2;
	sid['L']=3;
	sid['D']=4;
	sid['B']=5;
	std::ios::sync_with_stdio(0);
	int T;
	std::cin>>T;
	for(;T--;)[&]{
		std::vector<vi>f(6);
		for(int i=0;i<6;++i){
			f[i]=vi(4,i);
		}
		std::string s;
		std::cin>>s;
		for(int i=0;s[i];++i)if(std::isalpha(s[i])){
			auto rot=[&](int&a,int&b,int&c,int&d,int rev=1){
				vi vec({a,b,c,d});
				if(rev)std::rotate(vec.begin(),vec.begin()+1,vec.end());
				else std::rotate(vec.begin(),vec.end()-1,vec.end());
				a=vec[0];
				b=vec[1];
				c=vec[2];
				d=vec[3];
			};
			int cur=sid[s[i]];
			int cnt=1;
			if(s[i+1]=='2')cnt=2;
			else if(s[i+1]=='\'')cnt=3;
//			std::cerr<<i<<' '<<s[i]<<' '<<cnt<<' '<<cur<<'\n';
			for(int _=0;_<cnt;++_){
				std::rotate(f[cur].begin(),f[cur].begin()+1,f[cur].end());
				switch(cur){
					case 0:{
						rot(f[2][1],f[4][1],f[5][3],f[1][1]);
						rot(f[2][2],f[4][2],f[5][0],f[1][2]);
						break;
					}
					case 1:{
						rot(f[2][3],f[0][3],f[5][3],f[3][3]);
						rot(f[2][2],f[0][2],f[5][2],f[3][2]);
						break;
					}
					case 2:{
						rot(f[0][0],f[1][1],f[3][2],f[4][3]);
						rot(f[0][3],f[1][0],f[3][1],f[4][2]);
						break;
					}
					case 3:{
						rot(f[2][0],f[4][0],f[5][2],f[1][0],0);
						rot(f[2][3],f[4][3],f[5][1],f[1][3],0);
						break;
					}
					case 4:{
						rot(f[2][0],f[0][0],f[5][0],f[3][0],0);
						rot(f[2][1],f[0][1],f[5][1],f[3][1],0);
						break;
					}
					case 5:{
						rot(f[0][1],f[1][2],f[3][3],f[4][0],0);
						rot(f[0][2],f[1][3],f[3][0],f[4][1],0);
						break;
					}
					
				}
			}
//			for(int i=0;i<6;++i){
//				deb[dpos[i][0]][dpos[i][1]]=f[i][3]|48;
//				deb[dpos[i][0]][dpos[i][1]+1]=f[i][2]|48;
//				deb[dpos[i][0]+1][dpos[i][1]+1]=f[i][1]|48;
//				deb[dpos[i][0]+1][dpos[i][1]]=f[i][0]|48;
//			}
//			for(int i=0;i<6;++i){
//				std::cerr<<deb[i]<<'\n';
//			}
		}
		std::sort(all(f));
		for(int i=0;i<6;++i){
			if(f[i]!=vi(4,i)){
				puts("NO");
				return;
			}
		}
		puts("YES");
	}();
}
/*
6
D2D2
R2R2
L2L2
U2U2
F2F2
B2B2
*/

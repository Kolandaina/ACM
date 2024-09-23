#include<stdio.h>
#include<vector>
using namespace std;
int Dig(int x){
	int res=0;
	while(x>0){
		res++;
		x/=10;
	}
	return res;
}
int Len(pair<int,int>P){
	return Dig(P.first)+P.second+2;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	vector<pair<int,int>>A;
	A.push_back(make_pair(1,k));
	while(A.size()<n&&Len(A.back())>m){
		int x=A.back().first;
		if(Dig(x)+2>=m){
			printf("-1");
			return 0;
		}
		int l=Len(A.back());
		l-=m;
		A.back().second-=l;
		A.push_back(make_pair(x<<1,l<<1));
	}
	if(Len(A.back())>m){
		printf("-1");
		return 0;
	}
	while(A.size()<n){
		auto P=A.back();
		if(P.second==1){
			A.pop_back();
		}else{
			A.back().second--;
		}
		A.push_back(make_pair(P.first<<1,2));
		if(Len(A.back())>m){
			printf("-1");
			return 0;
		}
	}
	for(auto T:A){
		printf("{%d}",T.first);
		for(int i=T.second;i>0;i--){
			printf(",");
		}
		puts("");
	}
	return 0;
}

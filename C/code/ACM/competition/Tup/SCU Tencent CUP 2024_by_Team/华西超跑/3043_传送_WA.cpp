#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define N 3500000
vector<int>G[N],H[N];
void Link(int x,int y){
	G[x].push_back(y);
}
class Pool{
	int Ct;
	public:
		void Init(int n){
			Ct=n;
		}
		int GetNode(){
			Ct++;
			G[Ct].clear();
			return Ct;
		}
		int Size(){
			return Ct;
		}
}P;
struct SegmentNode{
	int Ls,Rs;
}T[800000];
void Build(int p,int lf,int rt,bool tag){
	if(lf<rt){
		T[p].Ls=P.GetNode();
		T[p].Rs=P.GetNode();
		if(tag==true){
			Link(p,T[p].Rs);
			Link(p,T[p].Ls);
		}else{
			Link(T[p].Ls,p);
			Link(T[p].Rs,p);
		}
		Build(T[p].Ls,lf,lf+rt>>1,tag);
		Build(T[p].Rs,lf+rt+2>>1,rt,tag);
	}else if(tag==true){
		Link(p,lf);
	}else{
		Link(rt,p);
	}
}
void LinkSegment(int p,int lf,int rt,int l,int r,int f,bool tag){
	if(l<=lf&&rt<=r){
		if(tag==true){
			Link(f,p);
		}else{
			Link(p,f);
		}
	}else{
		int mid=lf+rt>>1;
		if(l<=mid){
			LinkSegment(T[p].Ls,lf,mid,l,r,f,tag);
		}
		if(r>mid){
			LinkSegment(T[p].Rs,mid+1,rt,l,r,f,tag);
		}
	}
}
int dfn[N],low[N],bel[N],CT,SCC;
void Tarjan(int x){
	static vector<int>S;
	CT++;
	dfn[x]=low[x]=CT;
	S.push_back(x);
	for(int T:G[x]){
		if(dfn[T]==0){
			Tarjan(T);
			low[x]=min(low[x],low[T]);
		}else if(bel[T]==0){
			low[x]=min(low[x],dfn[T]);
		}
	}
	if(dfn[x]==low[x]){
		SCC++;
		int u;
		do{
			u=S.back();
			S.pop_back();
			bel[u]=SCC;
		}while(u!=x);
	}
}
int fl[N],fr[N];
bool vis[N];
void DP(int x){
	if(vis[x]==false){
		vis[x]=true;
		for(int T:H[x]){
			DP(T);
			fl[x]=min(fl[x],fl[T]);
			fr[x]=max(fr[x],fr[T]);
		}
	}
}
void Solve(){
	CT=SCC=0;
	int n,m;
	scanf("%d%d",&n,&m);
	P.Init(n);
	int In=P.GetNode(),Out=P.GetNode();
	Build(In,1,n,false);
	Build(Out,1,n,true);
	for(int i=0;i<m;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int f=P.GetNode();
		LinkSegment(In,1,n,a,b,f,false);
		LinkSegment(Out,1,n,c,d,f,true);
	}
	int s=P.Size();
	for(int i=1;i<=s;i++){
		dfn[i]=bel[i]=0;
	}
	for(int i=1;i<=s;i++){
		Tarjan(i);
	}
	for(int i=1;i<=SCC;i++){
		H[i].clear();
		fl[i]=N;
		fr[i]=0;
	}
	for(int i=1;i<=s;i++){
		for(int T:G[i]){
			if(bel[i]!=bel[T]){
				H[bel[i]].push_back(bel[T]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		fl[bel[i]]=min(fl[bel[i]],i);
		fr[bel[i]]=max(fr[bel[i]],i);
	}
	for(int i=1;i<=SCC;i++){
		vis[i]=false;
	}
	for(int i=1;i<=SCC;i++){
		DP(i);
	}
	for(int i=1;i<=n;i++){
		printf("%d %d\n",fl[bel[i]],fr[bel[i]]);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		Solve();
	}
	return 0;
}

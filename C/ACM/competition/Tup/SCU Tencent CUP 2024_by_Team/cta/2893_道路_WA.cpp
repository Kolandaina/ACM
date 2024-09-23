#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,fa[N],dep[N],vis[N];
vector<int>v,vec[N];
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
void DFS(int x){
	dep[x]=dep[fa[x]]+1;
	for(auto t:vec[x])DFS(t);
}
int cmp(int x,int y){return dep[x]<dep[y];}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=2;i<=n;i++)fa[i]=read(),vec[fa[i]].push_back(i);
	for(int i=1;i<=n;i++)if(vec[i].empty())v.push_back(i);
	sort(v.begin(),v.end(),cmp);
	int mn=n+1,mx=0;
	for(auto t:v){
		int cnt=1;
		while(fa[t]!=1&&!vis[fa[t]])t=fa[t],vis[t]=1,cnt++;
		mn=min(mn,cnt);
		mx=max(mx,cnt);
	}
	return cout<<mx-mn<<endl,0;
}

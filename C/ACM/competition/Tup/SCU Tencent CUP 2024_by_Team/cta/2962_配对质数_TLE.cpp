#include<bits/stdc++.h>
using namespace std;
const int NL=4e6+1,N=4e6+10;
int t,n,m,pd,lst,nw,lstnw,vis[N],pr[N];
vector<int>ans;
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
signed main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	t=read(),vis[1]=1;
	for(int i=2;i<=NL;i++){
		if(!vis[i])pr[++m]=i;
		for(int j=1;j<=m&&pr[j]*i<=NL;j++){
			vis[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
	while(t--){
		n=read()<<1,lst=n,pd=0;
		ans.clear(),ans.push_back(n);
		while(lst>=1){
			nw=pr[lower_bound(pr+1,pr+1+m,1+lst)-pr];
			lst=nw-lst-1,ans.push_back(lst);
		}
		reverse(ans.begin(),ans.end());
		if(ans[0])return cout<<n<<endl,0;
		if(ans.back()!=n)return cout<<n<<endl,0;
		for(auto t:ans)if(t%2)return cout<<n<<endl,0;
		for(int i=0;i<ans.size()-1;i++){
			if(ans[i]+1>ans[i+1])return cout<<n<<endl,0;
			for(int j=ans[i]+1;j<=ans[i+1];j++){
				if(j>ans[i+1]+1+ans[i]-j)break;
			
			
			
			//	printf("%d %d\n",j,ans[i+1]+1+ans[i]-j);
				if(vis[ans[i+1]+1+ans[i]]){return cout<<n<<endl,0;}
			}
		}
	}
	
	return 0;
}


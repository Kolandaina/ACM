#include <iostream>
const int N=2e5+5;
int fa[N],dl[N],dis[N],cnt[N];
int maxn=-1,minn=0x3f3f3f3f;
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int x;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		fa[i]=x;
		cnt[x]++;
	}
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		if(cnt[i]==0)dl[++r]=i;
	}
	dis[1]=1;
	while(l<=r){
		int pos=dl[l++];
		if(dis[fa[pos]]==0){
			dis[fa[pos]]=dis[pos]+1;
			dl[++r]=fa[pos];
		}
		else {
			maxn=max(maxn,dis[pos]);
			minn=min(minn,dis[pos]);
		}
	}
	printf("%d\n",maxn-minn);
	return 0;
}


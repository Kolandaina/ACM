#include<bits/stdc++.h>
#define int long long
using namespace std;

int V,n1,n2,n3;
int va[2005],vb[2005],vc[2005];
int wa[2005],wb[2005],wc[2005];
int fa[2005],fb[2005],fc[2005];

signed main(){
	cin>>V>>n1>>n2>>n3;
	for(int i=1;i<=n1;i++)cin>>va[i]>>wa[i];
	for(int i=1;i<=n2;i++)cin>>vb[i]>>wb[i];
	for(int i=1;i<=n3;i++)cin>>vc[i]>>wc[i];
	
	for(int i=1;i<=n1;i++)
		for(int j=V;j>=va[i];j--)
			fa[j]=max(fa[j],fa[j-va[i]]+wa[i]);
	
	for(int i=1;i<=n2;i++)
		for(int j=V;j>=vb[i];j--)
			fb[j]=max(fb[j],fb[j-vb[i]]+wb[i]);
			
	for(int i=1;i<=n3;i++)
		for(int j=V;j>=vc[i];j--)
			fc[j]=max(fc[j],fc[j-vc[i]]+wc[i]);
	
	int ans=0;
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V-i;j++)
		{
			int k=V-i-j;
			ans=max(ans,fa[i]*fb[j]*fc[k]);
		}
		cout<<ans;
	
	return 0;
}

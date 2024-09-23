#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,m3;
long long f1[2010],f2[2010],f3[2010],ff[2010],f[2010];
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
    cin>>n>>m1>>m2>>m3;
    for(int i=1;i<=m1;i++)
    {
	  int v,w;
	  cin>>v>>w;
	  for(int j=0;j<=n;j++)
	     if(j-v>=0)
	        f1[j]=max(f1[j],f1[j-v]+w);
	}
	for(int i=1;i<=m2;i++)
    {
	  int v,w;
	  cin>>v>>w;
	  for(int j=0;j<=n;j++)
	     if(j-v>=0)
	        f2[j]=max(f2[j],f2[j-v]+w);
	}
	for(int i=1;i<=m3;i++)
    {
	  int v,w;
	  cin>>v>>w;
	  for(int j=0;j<=n;j++)
	     if(j-v>=0)
	        f3[j]=max(f3[j],f3[j-v]+w);
	}
	for(int i=0;i<=n;i++)
	   for(int j=0;j<=n;j++)
	       if(i+j<=n) ff[i+j]=max(ff[i+j],f1[i]*f2[j]);
	for(int i=0;i<=n;i++)
	    for(int j=0;j<=n;j++)
	        if(i+j<=n) f[i+j]=max(f[i+j],ff[i]*f3[j]);
	cout<<f[n];
	return 0;
}


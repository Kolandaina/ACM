#include<bits/stdc++.h>
using namespace std;
int n,a[100001];
void qsort(int l,int r)
{
	if(l>=r) return;
	int i,j,x;
	i=l,j=r,x=a[l];
	while(i<j)
	{
		while(a[j]>=x&&i<j) j--;
		while(a[i]<=x&&i<j) i++;
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	swap(a[l],a[i]);
	qsort(l,j-1);
	qsort(j+1,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}

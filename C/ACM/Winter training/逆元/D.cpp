#include<iostream>
using namespace std;
#define int long long
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
signed main(){
	
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
    {
		int sum=1;
		int x,y;
		cin>>x>>y;
		int k=gcd(x,y);
		while(1)
        {
			if(x<y) swap(x,y);
			int m1=x/k;
			int m2=y/k;
			if(m1%(m2+1)==0) sum++;
			else break;
			x=m1/(1+m2)*k;
		}
        cout<<"Case #"<<i<<": "<<sum<<endl;
	} 
	return 0;
}
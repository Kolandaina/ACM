#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,c,n;
	cin>>n;
	while (n--)
	{
		cin>>a>>b;
		c=2*b;
		while (gcd(a, c) != b)
		{
			c+=b;
		}
		cout<<c<<endl;
	}
}
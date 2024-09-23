#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	int a,b,c,d,e,f;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b>>c>>d;
        f=b*d;
        e=a*d+b*c;
        cout<<e/gcd(e,f)<<" "<<f/gcd(e,f)<<endl;
    }
	return 0;
}
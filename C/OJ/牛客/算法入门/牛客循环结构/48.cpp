#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		int s=0;
		for(int j=a;j<=b;j++)
		{
			if((((j/100%10)*(j/10%10)))%10==j%10)
			{
				s++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}
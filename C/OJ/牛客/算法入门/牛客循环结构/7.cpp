#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	double a=0;
	for(double i=1;i<=m;i++)
	{
		a += 1/i;
	}
	printf("%.6f",a);
	return 0;
}
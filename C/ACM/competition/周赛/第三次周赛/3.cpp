/*#include<bits/stdc++.h>
using namespace std;
double m[1000000]={99999999};
int main()
{
	double a,b;
	cin>>a>>b;
	for(int i=0;i<100000;i++)
	{
		double t=pow(i+1,0.5);
		m[i]=b*i+a/t;
	}
	printf("%.6f",*min_element(m,m+1000000));
	return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
double m[1000];
int main()
{
	double a,b;
	cin>>a>>b;
	for(int i=0;i<1000;i++)
	{
		double t=pow(i+1,0.5);
		m[i]=b*i+a/t;
	}
	double x=*min_element(m,m+1000);
	printf("%.6f",x);
	return 0;
}
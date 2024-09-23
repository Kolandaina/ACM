#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double gpa[50],sc[50];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>gpa[i]>>sc[i];
	}
	double gp=0,s=0;
	for(int i=0;i<n;i++)
	{
		gp+=gpa[i]*sc[i];
		s+=sc[i];
	}
	printf("%.1f",gp/s);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m[10];
	for(int i=0;i<10;i++) 
	{
		scanf("%d",&m[i]);
	}
	int a=0,b=0;
	for(int i=0;i<10;i++)
	{
		if(m[i]>0) 
		{
			a++;
		}
		if(m[i]<0) 
		{
			b++;
		}
	}
	cout<<"positive:"<<a<<"\n";
	cout<<"negative:"<<b;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
char m[1000000];
int main()
{
	scanf("%s",&m);
	int n=strlen(m);
	for(int i=0;i<n;i++)
	{
		if(m[i]=='5')
		{
			m[i]='*';
		}
	}
	cout<<m;
	return 0;
}
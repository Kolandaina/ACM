#include<bits/stdc++.h>
using namespace std;
int main()
{
	int s=0;
	char m[10000];
	while(scanf("%s",&m)!=EOF)
	{
		if(m[0]=='.')
		{
			break;
		}
		int n=strlen(m);
		for(int i=0;i<n;i++)
		{
			if(m[i]=='a') s++;
		}
	}
	cout<<s;
	return 0;
}
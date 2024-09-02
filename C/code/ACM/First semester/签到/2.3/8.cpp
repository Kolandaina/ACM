#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[200]={0};
	while (~scanf("%s",s))
	{
		if (s[0]>=65&&s[0]<=90) cout<<s[0];
		else cout<<s[0]-32;
	}
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[200]={0};
	while (~scanf("%s",s))
	{
		if (s[0]>=65&&s[0]<=90) 
		{
			printf("%c",s[0]);
		}
		else
			printf("%c",s[0]-32); 
	}
}
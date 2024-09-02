#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[100];
	cin>>a;
	int n=strlen(a);
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]=='+') s++;
		if(a[i]=='-') s--;
	}
	cout<<s<<endl;
	return 0;
}

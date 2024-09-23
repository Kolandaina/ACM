#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	if(m==4||m==2||m%2!=0) cout<<"NO, you can't divide the watermelon into two even parts.";
	else cout<<"YES, you can divide the watermelon into two even parts.";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	int a=m/1%10;
	int b=m/10%10;
	int c=b*10+a;
	if(c>=3&&c<=5) cout<<"spring";
	else if(c>=6&&c<=8) cout<<"summer";
	else if(c>=9&&c<=11) cout<<"autumn";
	else if(c=12||c==1||c==2) cout<<"winter";
	return 0;
}
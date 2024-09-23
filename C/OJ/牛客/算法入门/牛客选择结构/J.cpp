#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m;
	cin>>m;
	if(m%400==0||(m%100!=0&&m%4==0)) cout<<"yes";
	else cout<<"no";
	return 0;
}
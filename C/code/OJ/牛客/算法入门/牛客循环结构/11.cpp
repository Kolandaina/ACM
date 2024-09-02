#include<bits/stdc++.h>
using namespace std;
int mod(int x)
{
    if(x==1)return 0;
    if(x==2||x==3)return 1;
    else return mod(x-3)+2*mod(x-2)+mod(x-1);
}
int main()
{
    int a;
	cin>>a;
    cout<<mod(a);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10];
    int n;
    cin>>n;
    int x=0,y=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a[0]=='F') x++;
        if(a[0]=='A') y++;
    }
    if(x>y) cout<<"Yes"<<endl;
    if(x<y) cout<<"No"<<endl;
}
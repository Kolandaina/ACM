#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[20];
    cin>>a;
    int b[20]={0};
    for(int i=0;i<9;i++)
    {
        b[int(a[i])-48]++;
    }
    for(int i=0;i<10;i++)
    {
        if(b[i]==0) cout<<i;
    }
    return 0;
}
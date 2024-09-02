#include<bits/stdc++.h>
using namespace std;
int aa[10000];
int bb[10000];
int main()
{
    int a,b,o=0;
    cin>>a;
    for(int i=0;i<a;i++)
    {
        cin>>b;
        if(bb[b]==1)
        {
            continue;
        }
        else
        {
            aa[o++]=b;
        }
        bb[b]=1;
    }
    for(int i=0;i<o;i++)
    {
        cout<<aa[i]<<" ";
    }
    return 0;
}
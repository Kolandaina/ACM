#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int k=0;k<n;k++)
    {
        int m,s=0;
        cin>>m;
        char a[1000];
        for(int i=1;i<=m;i++)
        {
            cin>>a;
            if(a[0]=='b' && a[1]=='n' && a[2]=='u'&&a[3]=='1'&&a[4]=='6') s++;
        }
        cout<<s<<endl;
    }
    return 0;
}
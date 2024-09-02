#include<bits/stdc++.h>
using namespace std;
int b[26];
int main()
{
    char a[101];
    int sum=0,flag=1,ans;
    cin>>a;
    for(int j=0;j<26;j++)
    {
        for(int i=0;i<strlen(a);i++)
        {
            if(a[i]=='a'+j) b[j]++;
        }
    }
    sort(b,b+26);
    int cnt=unique(b,b+26)-b;
    if(b[0]==0) ans=b[cnt-1]-b[1];
    else ans=b[cnt-1]-b[0];
    if(ans==0||ans==1) flag=0;
    else
    {
        for(int i=2;i<=ans/2;i++)
        {
            if(ans%i==0)
            {
                flag=0;
                break;
            }
        }
    }
    if(flag) cout<<"Lucky Word"<<endl<<ans;
    else cout<<"No Answer"<<endl<<"0";
    return 0;
}
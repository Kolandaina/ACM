#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    char s[1000000];
    cin>>s;
    int mod=1000000007;
    int ans=0,k=0;
    int len=strlen(s);
    for(int i=len-1;i>=0;--i)
    {
        if(s[i]=='b') ++k;
        else
        {
            ans=(ans+k)%mod;
            k=k*2%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}
#include<iostream>
using namespace std;
#define int long long
const int N=1e6;
int a[N],b[N];
int t,n,j=1,suma,sumb,s;
signed main()
{  
    cin>>t;
    while(t--)
    {
        cin>>n;
        suma=0,sumb=0,s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>b[i]; 
            suma+=a[i];
            sumb+=b[i];
        }
        for(int i=1;i<=n;i++)
        {
            suma-=a[i];
            s+=b[i]*suma;
            sumb-=b[i];
            s+=a[i]*sumb;
        }
        cout<<"Case "<<j++<<": "<<s<<endl;
    }
    return  0;
}
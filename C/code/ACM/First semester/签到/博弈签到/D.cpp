#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,l,c,d,p,nl,np;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    cout<<min(int((k*l)/nl),min(int(c*d),int(p/np)));
    return 0;
}
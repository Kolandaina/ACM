#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++)
    {
        int n,aa[10000],s=0;
        double a=0,ans=0;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>aa[i];
            s+=aa[i];
        }
        a=1.0*s/n*1.0;
        for(int i=0;i<n;i++)
        {
            ans+=1.0*(aa[i]-a)*(aa[i]-a);
        }
        cout<<*max_element(aa,aa+n)-*min_element(aa,aa+n)<<" ";
        printf("%.3f\n",1.0*ans/n);
    }
}
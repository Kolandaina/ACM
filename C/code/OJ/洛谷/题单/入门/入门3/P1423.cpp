#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b=2;
    cin>>a;
    double s=0;
    for(int i=1;;i++)
    {
        s+=b;
        if(s>=a)
        {
            cout<<i<<endl;
            return 0;
        }
        b=b*0.98;
    }
    return 0;
}
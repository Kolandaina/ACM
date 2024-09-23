#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int s=1;
    for(int i=n;i>0;i--)
    {
        for(int j=i;j>0;j--)
        {
            if(s<10) cout<<"0"<<s++;
            else cout<<s++;
        }
        cout<<endl;
    }
    return 0;
}
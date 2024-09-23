#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int s=0;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                s++;
            }
        }
        cout<<s<<" ";
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a=n;
    int arr[1000];
    int j=1000;
    if(n==1)
    {
        cout<<"1"<<endl;
        return 0;
    }
    for(int i=1;i<1000;i++)
    {
        if(n%2==0)
        {
            n=n/2;
            arr[i]=n;
        }
        else
        {
            n=n*3+1;
            arr[i]=n;
        }
        if(n==1)
        {
            j=i;
            break;
        }
    }
    for(int i=j;i>=1;i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<a<<endl;
    return 0;
}
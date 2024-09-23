#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        if(n%(m+1)) cout<<"first"<<endl;
        else cout<<"second"<<endl;
    }
    return 0;
}
#include<iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int b=1,n=1;
    for(int i=1;i<a;i++)
    {
        n+=b;
        b++;
        if(n>a)
        {
            n-=a;
            cout<<n<<" ";
        }
        else cout<<n<<" ";
    }
    return 0;
}
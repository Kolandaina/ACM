#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[256];
    cin.getline(a,256);
    int n=strlen(a);
    int s=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>='0'&&a[i]<='9') s++;
    }
    cout<<s<<endl;
    return 0;
}
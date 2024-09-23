#include<bits/stdc++.h>
using namespace std;
const char a[]={'3','1','4','1','5','9','2','6','5','3','5','8','9','7','9','3','2','3','8','4','6','2','6','4','3','3','8','3','2','7'};
int main()
{
    
    char b[30];
    int n;
    cin>>n;
    while(n--)
    {
        cin>>b;
        int s=0;
        int m=strlen(b);
        for(int i=0;i<m;i++)
        {
            if(b[i]==a[i]) s++;
            else break;
        }
        cout<<s<<endl;
    }
    return 0;
}
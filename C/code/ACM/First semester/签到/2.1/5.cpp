#include<iostream>
using namespace std;
typedef struct node
{
    char a[10];
    char b[10];
}x;
int main()
{
    int n,m;
    cin>>n>>m;
    x f[1001];
    for(int i=0;i<n;i++) cin>>f[i].a;
    for(int i=0;i<m;i++) cin>>f[i].b;
    int s=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(f[i].a[3]==f[j].b[0]&&f[i].a[4]==f[j].b[1]&&f[i].a[5]==f[j].b[2])
            {
                s++;
                break;
            }
        }
    }
    cout<<s<<endl;
    return 0;
}
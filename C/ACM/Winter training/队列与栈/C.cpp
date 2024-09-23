#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int m;
        char a[10];
        cin>>m>>a;
        if(a[2]=='F')
        {
            int hh=0,tt=-1,c;
            char b[10];
            int q[1000];
            for(int i=1;i<=m;i++)
            {
                cin>>b;
                if(b[0]=='I')
                {
                    cin>>c;
                    q[++tt]=c;
                }
                if(hh>tt)
                {
                    cout<<"None"<<endl;
                    continue;
                }
                if(b[0]=='O') cout<<q[hh++]<<endl;
            }
        }
        else
        {
            int hh=0,tt=-1,c;
            char b[10];
            int q[1000];
            for(int i=1;i<=m;i++)
            {
                cin>>b;
                if(b[0]=='I')
                {
                    cin>>c;
                    q[++tt]=c;
                }
                if(hh>tt)
                {
                    cout<<"None"<<endl;
                    continue;
                }
                if(b[0]=='O') cout<<q[tt--]<<endl;
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a,b;
int vis[10000];
struct node
{
    int x;
    int step;
};
bool rule(int x)
{
    if(x<1000||x>=10000) return false;
    for(int i=2;i*i<=x;i++) if(x%i==0) return false;
    return true;
}
void bfs()
{
    queue<node>q;
    node start;
    start.x=a;
    start.step=0;
    q.push(start);
    vis[start.x]=1;
    while(q.empty()!=0)
    {
        node now;
        now=q.front();
        q.pop();
        if(now.x==b)
        {
            cout<<now.step<<endl;
            return;
        }
        for(int i=1;i<10;i+=2)
        {
            node temp;
            temp.x=now.x/10*10+i;
            if(rule(temp.x)&&vis[temp.x]==0)
            {
                temp.step=now.step+1;
                q.push(temp);
            }
        }
        for(int i=0;i<10;i++)
        {
            node temp;
            temp.x=now.x/100*100+now.x%10+i*10;
            if(rule(temp.x)&&vis[temp.x]==0)
            {
                temp.step=now.step+1;
                q.push(temp);
            }
        }
        for(int i=1;i<10;i++)
        {
            node temp;
            temp.x=now.x/1000*1000+now.x%100+i*100;
            if(rule(temp.x)&&vis[temp.x]==0)
            {
                temp.step=now.step+1;
                q.push(temp);
            }
        }
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        bfs();
    }
}
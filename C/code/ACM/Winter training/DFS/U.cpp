#include <iostream>
#include <cstring>
using namespace std;
const int MAXN=1000;
bool maze[5][5];
bool visited[5][5];
int head=0,tail=0;
int d[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Road
{
    int r,c;
    int f;
};
Road q[MAXN];
void bfs()
{
	while(head<tail)
	{
        Road front=q[head];
        if(front.c==4&&front.r==4) break;
        for(int i=0;i<4;i++)
		{
            Road last;
            last.r=front.r+d[i][0];
            last.c=front.c+d[i][1];
            if(last.r>=0&&last.r<=4&&last.c<=4&&last.c>=0)
			{
                if(!visited[last.r][last.c]&&!maze[last.r][last.c]) 
				{
                    last.f=head; 
                    q[tail++]=last;
                    visited[last.r][last.c]=1;
                }
            }
        }
        head++;
    }
}
 
int main()
{
    int path[30];
    for(int i=0;i<5;i++)
	{
        for(int j=0;j<5;j++)
		{
            cin>>maze[i][j];
        }
    }
    //memset(visited,0,sizeof(visited));
	Road a={0,0,-1};
    q[tail++]=a;
    visited[0][0]=1;
    bfs();
    int i=0;
    while(q[head].f>=0)
	{
        path[i++]=q[head].f;
        head=path[i-1];
    }
    for(int j=i-1;j>=0;j--)
	{
        cout<<"("<<q[path[j]].r<<", "<<q[path[j]].c<<")"<<endl;
    }
    cout<<"("<<4<<", "<<4<<")"<<endl;
    return 0;
}
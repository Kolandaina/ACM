#include<iostream>
#include<iomanip>
using namespace std;
const int N=105;
int n,ans[N],m;
bool vis[N][N];
char s[N][N];
int dis[8][2]={{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};

bool rule(int x,int y){
	return !vis[x][y]&&x>=1&&x<=n&&y>=1&&y<=m&&s[x][y]=='W';
}
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int dx=x+dis[i][0];
		int dy=y+dis[i][1];
		if(rule(dx,dy)){
			vis[dx][dy]=1;
			s[dx][dy]='.';
			dfs(dx,dy);
		}
	}
}
int main(){
	cin>>n>>m;
	int ans=0;
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='W')
			{
                dfs(i,j);
                s[i][j]='.';
                ans++;
            }
        }
    }
	cout<<ans<<endl;
	return 0;
}
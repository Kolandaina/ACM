#include<iostream>
using namespace std;
#define int long long
char f[25][25];
int w,h,sx,sy;
int dx[4]={-1,0,1,0 };
int dy[4]={0,1,0,-1 };
int dfs(int x, int y)
{
	int ans=1;
	f[x][y]='#';
	for(int i=0;i<=3;i++)
    {
		int nx=x+dx[i],ny=y+dy[i];
		if (nx<=h&&nx>=1&&ny<=w&&ny>=1&&f[nx][ny]== '.') ans += dfs(nx, ny);
	}
	return ans;
}
signed main()
{
	while(cin>>w>>h&&(w!=0&&h!=0))
    {
		for(int i=1;i<=h;i++)
        {
			for(int j=1;j<=w;j++)
            {
				cin >> f[i][j];
				if (f[i][j] == '@')
                {
                    sx=i;
                    sy=j;
                }
			}
		}
		cout<<dfs(sx, sy)<<endl;
	}
	return 0;
}
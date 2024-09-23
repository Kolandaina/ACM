#include <bits/stdc++.h>

int n, X1, X2, Y1, Y2, mp[1000][1000];
bool vis[1000][1000];
int next[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

struct node{
	int x, y, step;
};

void bfs(){
	std::queue<node> q;
	q.push({X1, Y1, 0});
	vis[X1][Y1] = true;

	while(!q.empty()){
		node e = q.front();
		q.pop();

		if(e.x == X2 && e.y == Y2){
			std::cout << e.step;
			return ;
		}

		for(int i = 0; i < 4; i++){
			int X = e.x + next[i][0];
			int Y = e.y + next[i][1];
			if(X >= 0 && X < n && Y >= 0 && Y < n && vis[X][Y] == false){
				vis[X][Y] = true;
				q.push({X, Y, e.step + 1});
			}
		}
	}

	std::cout << -1;
}

int main(){
	std::cin >> n;
	for(int i = 0; i < n; i++){
		std::string s;
		std::cin >> s;
		for(int j = 0; j < n; j++)
			mp[i][j] = (int)s[j] - '0';
	}
	std::cin >> X1 >> Y1 >> X2 >> Y2;
	X1--, Y1--, X2--, Y2--;

	bfs();

	return 0;
}
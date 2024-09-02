#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5;
int n, fa[N+5], h[N+5], dep[N+5], vis[N+5];
struct node{
	int id, dep;
}g[N+5];
vector<int> to[N+5], res;
vector<node> leaf;

void dfs(int x){
	dep[x] = dep[fa[x]] + 1;
	for (auto &y: to[x])
	  dfs(y);
}

bool cmp(node x, node y){
	return x.dep < y.dep;
}

int main(){
	scanf("%d",&n);
	for (int i = 2; i <= n; i ++){
		scanf("%d",&fa[i]);
		h[fa[i]] = 1;
		to[fa[i]].push_back(i);
	}
	dfs(1), h[1] = vis[1] = 1;
	for (int i = 1; i <= n; i ++)
	  if (h[i] == 0)
	    leaf.push_back((node){i, dep[i]});
	sort(leaf.begin(), leaf.end(), cmp);
	for (auto &it: leaf){
		int x = it.id, cnt = 0;
		while (vis[fa[x]] == 0){
			cnt ++;
			vis[fa[x]] = 1;
			x = fa[x];
		}
		res.push_back(cnt);
	}
	sort(res.begin(), res.end());
	printf("%d\n",res[res.size()-1]-res[0]);
	return 0;
}


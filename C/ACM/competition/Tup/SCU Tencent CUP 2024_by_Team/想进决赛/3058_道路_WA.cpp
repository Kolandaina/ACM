#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 2e5;
int n;
struct node{
	int id, fa, v, dep;
	int vis;
}t[N+5];
vector<int> to[N+5], leaf, res;

void dfs(int x){
	t[x].dep = t[t[x].fa].dep + 1;
	for (auto &y: to[x])
	  dfs(y);
}

bool cmp(node x, node y){
	return x.dep < y.dep;
}

int main(){
	scanf("%d",&n);
	for (int i = 1; i <= n; i ++)
	  t[i].id = i;
	for (int i = 2; i <= n; i ++){
		scanf("%d",&t[i].fa);
		t[t[i].fa].v = 1;
		to[t[i].fa].push_back(i);
	}
	dfs(1);
	t[1].v = t[1].vis = 1;
	sort(t+1, t+n+1, cmp);
	for (int i = 1; i <= n; i ++)
	  if (t[i].v == 0)
	    leaf.push_back(i);
	for (auto &i: leaf){
		int x = i, cnt = 0;
		while (t[t[x].fa].vis == 0){
			cnt ++;
			t[t[x].fa].vis = 1;
			x = t[x].fa;
		}
		res.push_back(cnt);
	}
	sort(res.begin(), res.end());
	printf("%d\n",res[res.size()-1]-res[0]);
	return 0;
}


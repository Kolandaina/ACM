#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>
#include<queue>
#define endl '\n'
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
const int N = 2e5+10,M = 2*N;
int n,m;
int h[N],e[M],ne[M],idx;
int d[N];
bool st[N];
int dis[N];
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void distra()
{
	dis[1]=0;
	priority_queue<PII,vector<PII>,greater<PII>> heap;
	heap.push({0,1});
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		int ver = t.second,di = t.first;
		if(st[ver]) continue;
		st[ver] = true;
		for(int i=h[ver];i!=-1;i=ne[i]){
			int j=e[i];
			if(dis[j]>di+1){
				dis[j] = di+1;
				heap.push({dis[j],j});
			}
		}
	}
//	cout<<"-----"<<endl;
	
}
inline void solved(){
	/*!!!!!!!!!!!*/
	cin>>n;
	memset(h,-1,sizeof h);
	memset(dis,0x3f,sizeof dis);
	for(int i=2;i<=n;i++){
		int a;
		cin>>a;
		add(i,a);
		add(a,i);
		d[a]++;
		d[i]++;
	}
	distra();
	vector<int> ans;
	for(int i=2;i<=n;i++){
		if(d[i]==1){
			ans.push_back(dis[i]);
		}
	}
	sort(ans.begin(),ans.end());
	
	int ret=inf;
	for(int i=1;i<ans.size();i++){
		ret = min(ans[i]-ans[i-1],ret);
	}
	cout<<ret;
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solved();
	}
	return 0;
}

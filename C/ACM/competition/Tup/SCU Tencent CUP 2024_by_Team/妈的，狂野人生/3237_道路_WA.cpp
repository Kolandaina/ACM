#include<bits/stdc++.h>


using namespace std;
int arr[200009];
vector<int> node[200009];

multiset<int> dfs(int root)
{
	multiset<int>st,stt;
	for(int i=0;i<node[root].size();i++)
	{
		stt=dfs(node[root][i]);
		if(st.size()<stt.size()) swap(stt,st);
		for(multiset<int>::iterator it=stt.begin();it!=stt.end();it++)
		{
			st.insert(*it);
		}
	}
	if(node[root].size()==0) st.insert(1);
	else
	{
		if(root==1 )  return st;
		int val=*st.begin();
		st.erase(st.begin());
		val++;
		st.insert(val);
	}
	return st;
}

int main()
{
	int n,a;
	scanf("%d",&n);
	if(n==1)
	{
		printf("0\n");
		return 0;
	}
    for(int i=2;i<=n;i++)
    {
      scanf("%d",&a);	
      node[a].push_back(i);	
	}
	multiset<int> st=dfs(1);
	int mx=*(--st.end());
	int mn=*st.begin();
		for(multiset<int>::iterator it=st.begin();it!=st.end();it++)
		{
			//printf("%d\n",*it);
		}
	printf("%d",mx-mn);
	return 0;
}

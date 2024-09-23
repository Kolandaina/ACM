#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int m;
		cin>>m;
		if(m==0) cout<<"2 4"<<endl;
		else if(m==1) cout<<"0 2"<<endl;
		else if(m==2) cout<<"3 2"<<endl;
		else if(m==3) cout<<"3 2"<<endl;
		else if(m==4) cout<<"1 3"<<endl;
		else if(m==5) cout<<"3 2"<<endl;
		else if(m==6) cout<<"3 3"<<endl;
		else if(m==7) cout<<"1 2"<<endl;
		else if(m==8) cout<<"3 4"<<endl;
		else cout<<"3 3"<<endl;
	}
	return 0;
}
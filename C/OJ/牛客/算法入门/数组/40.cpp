#include<bits/stdc++.h>
using namespace std;
int main()
{
   
	int n;
	cin>>n;
	string s[1010];
	for (int i=0; i<n;i++) cin>>s[i];
	int len,sum=0;
	for(int i=0;i<n;i++){
		len = s[i].size();
		for (int j=0; j<len-3;j++)
        {
			int x=0;
			if (s[i][j]=='A' || s[i][j]=='a') x++;
			if (s[i][j+1]=='L' || s[i][j+1]=='l') x++;
			if (s[i][j+2]=='A' || s[i][j+2]=='a') x++;
			if (s[i][j+3]=='N' || s[i][j+3]=='n') x++;
			if (x==4)
            {
				sum++;
                break;
			}
		}
	}
	cout<<sum;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

void turn(int &a, int &b, int &c, int &d)
{
	int t;
	t=a, a=b, b=c, c=d, d=t;
}
bool je(int a[])
{
	if(a[1]==a[2] && a[2]==a[3] && a[3]==a[4])
		return true;
	return false;
}

int main()
{
	//freopen("in.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		int U[5]={0,3,3,3,3}, D[5]={0,6,6,6,6}, F[5]={0,1,1,1,1}, B[5]={0,2,2,2,2}, L[5]={0,5,5,5,5}, R[5]={0,4,4,4,4};
		string s;
		cin>>s;
		int t=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i+1]==39)
			{
				if(s[i]=='R' || s[i]=='L')
				{
					turn(U[2], B[3], D[4], F[2]);
					turn(U[4], B[1], D[2], F[4]);
					turn(U[2], B[3], D[4], F[2]);
					turn(U[4], B[1], D[2], F[4]);
					turn(U[2], B[3], D[4], F[2]);
					turn(U[4], B[1], D[2], F[4]);
					turn(R[1], R[2], R[4], R[3]);
				}
				if(s[i]=='U' || s[i]=='D')
				{
					turn(F[2], L[2], B[2], R[2]);
					turn(F[1], L[1], B[1], R[1]);
					turn(F[2], L[2], B[2], R[2]);
					turn(F[1], L[1], B[1], R[1]);
					turn(F[2], L[2], B[2], R[2]);
					turn(F[1], L[1], B[1], R[1]);
					turn(U[1], U[2], U[4], U[3]);
				}
				if(s[i]=='F' || s[i]=='B')
				{
					turn(U[3], R[1], D[4], L[4]);
					turn(U[4], R[3], D[3], L[2]); 
					turn(U[3], R[1], D[4], L[4]);
					turn(U[4], R[3], D[3], L[2]); 
					turn(U[3], R[1], D[4], L[4]);
					turn(U[4], R[3], D[3], L[2]); 
					turn(F[1], F[2], F[4], F[3]);
				}
				i++;
			}
			else if(i+1==s.length() || s[i+1]>='A' && s[i+1]<='Z')
			{
				if(s[i]=='R' || s[i]=='L')
				{
					turn(U[2], B[3], D[4], F[2]);
					turn(U[4], B[1], D[2], F[4]);
					turn(R[1], R[2], R[4], R[3]);
					turn(R[1], R[2], R[4], R[3]);
					turn(R[1], R[2], R[4], R[3]);
				}
				if(s[i]=='U' || s[i]=='D')
				{
					turn(F[2], L[2], B[2], R[2]);
					turn(F[1], L[1], B[1], R[1]);
					turn(U[1], U[2], U[4], U[3]);
					turn(U[1], U[2], U[4], U[3]);
					turn(U[1], U[2], U[4], U[3]);
				}
				if(s[i]=='F' || s[i]=='B')
				{
					turn(U[3], R[1], D[4], L[4]);
					turn(U[4], R[3], D[3], L[2]); 
					turn(F[1], F[2], F[4], F[3]);
					turn(F[1], F[2], F[4], F[3]);
					turn(F[1], F[2], F[4], F[3]);
				}
			}
			else if(s[i+1]=='2')
			{
				if(s[i]=='R' || s[i]=='L')
				{
					turn(U[2], B[3], D[4], F[2]);
					turn(U[4], B[1], D[2], F[4]);
					turn(R[1], R[2], R[4], R[3]);
					turn(U[2], B[3], D[4], F[2]);
					turn(U[4], B[1], D[2], F[4]);
					turn(R[1], R[2], R[4], R[3]);
				}
				if(s[i]=='U' || s[i]=='D')
				{
					turn(F[2], L[2], B[2], R[2]);
					turn(F[1], L[1], B[1], R[1]);
					turn(U[1], U[2], U[4], U[3]);
					turn(F[2], L[2], B[2], R[2]);
					turn(F[1], L[1], B[1], R[1]);
					turn(U[1], U[2], U[4], U[3]);
				}
				if(s[i]=='F' || s[i]=='B')
				{
					turn(U[3], R[1], D[4], L[4]);
					turn(U[4], R[3], D[3], L[2]); 
					turn(F[1], F[2], F[4], F[3]);
					turn(U[3], R[1], D[4], L[4]);
					turn(U[4], R[3], D[3], L[2]); 
					turn(F[1], F[2], F[4], F[3]);
				}
				i++;
			}
			t++;
		}
		
		if(je(B) && je(F) && je(L) &&je(R) && je(D))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}

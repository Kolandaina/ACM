#include<bits/stdc++.h>
using namespace std;
int t[25];
void init()
{
	for(int i=0;i<=5;i++)
	{
		t[i*4+1]=i;
		t[i*4+2]=i;
		t[i*4+3]=i;
		t[i*4+4]=i;
	}
}
void R()
{
	int nine=t[9];
	t[9]=t[11];
	t[11]=t[12];
	t[12]=t[10];
	t[10]=nine;
	int two=t[2];
	int four=t[4];
	t[2]=t[6];
	t[4]=t[8];
	t[6]=t[16];
	t[8]=t[14];
	t[16]=t[20];
	t[14]=t[18];
	t[20]=two;
	t[18]=four;
}

void L()
{
	int twoone=t[21];
	t[21]=t[22];
	t[22]=t[24];
	t[24]=t[23];
	t[23]=twoone;
	
	int one=t[1];
	int three=t[3];
	t[1]=t[19];
	t[3]=t[17];
	t[17]=t[13];
	t[19]=t[15];
	t[13]=t[7];
	t[15]=t[5];
	t[7]=three;
	t[5]=one;
}

void F()
{
	int five=t[5];
	t[5]=t[7];
	t[7]=t[8];
	t[8]=t[6];
	t[6]=five;
	int three= t[3];
	int four=t[4];
	t[3]=t[23];
	t[4]=t[21];
	t[21]=t[15];
	t[23]=t[16];
	t[15]=t[11];
	t[16]=t[9];
	t[11]=four;
	t[9]=three;
}

void B()
{
	int oneseven=t[17];
	t[17]=t[18];
	t[18]=t[20];
	t[20]=t[19];
	t[19]=oneseven;
	int one=t[1];
	int two=t[2];
	t[1]=t[10];
	t[2]=t[12];
	t[10]=t[14];
	t[12]=t[13];
	t[14]=t[24];
	t[13]=t[22];
	t[24]=one;
	t[22]=two;
}

void U()
{
	int one=t[1];
	t[1]=t[3];
	t[3]=t[4];
	t[4]=t[2];
	t[2]=one;
	int five=t[5];
	int six=t[6];
	t[5]=t[9];
	t[6]=t[10];
	t[9]=t[18];
	t[10]=t[17];
	t[18]=t[22];
	t[17]=t[21];
	t[21]=six;
	t[22]=five;
}

void D()
{
	int onethree=t[13];
	t[13]=t[14];
	t[14]=t[16];
	t[16]=t[15];
	t[15]=onethree;
	int seven=t[7];
	int eight=t[8];
	t[7]=t[24];
	t[8]=t[23];
	t[24]=t[20];
	t[23]=t[19];
	t[20]=t[11];
	t[19]=t[12];
	t[11]=seven;
	t[12]=eight;
}
int n;
string s;
void work()
{
	init();
	int ls=s.length();
	s=s+' '+' '+' ';
	for(int i=0;i<ls;i++)
	{
		if(s[i]<='Z'&&s[i]>='A')
		{
			int cnt=1;
			if(s[i+1]=='\'')
			{
				cnt=3;
				if(s[i+2]<='9'&&s[i+2]>='0')cnt=cnt*(s[i+2]-'0');
			}
			else if(s[i+1]<='9'&&s[i+1]>='0')
			{
				cnt=cnt*(s[i+1]-'0');
			}
			for(int j=1;j<=cnt;j++)
			{
				if(s[i]=='R')R();
				if(s[i]=='L')L();
				if(s[i]=='B')B();
				if(s[i]=='F')F();
				if(s[i]=='U')U();
				if(s[i]=='D')D();
			}
		}
		else continue;
	}
	for(int i=0;i<=5;i++)
	{
		if(t[i*4+1]==t[i*4+2]&&t[i*4+2]==t[i*4+3]&&t[i*4+3]==t[i*4+4])continue;
		else 
		{
			cout<<"NO"<<endl;
			return ;
		}
	}
	cout<<"YES"<<endl;
	return;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		work();
	}
}

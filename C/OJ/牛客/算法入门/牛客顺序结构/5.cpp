/*#include<bits/stdc++.h>
using namespace std;
int main()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=i;j++)
		{
			cout<<j<<"*"<<i<<"="<<i*j<<" ";
		}
		cout<<"\n";
	}
	return 0;
}*/
#include<stdio.h>
int main()
{
    int i,j;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d*%d=%2d ",j,i,i*j);
        }
        printf("\n");
    }
    return 0;
}
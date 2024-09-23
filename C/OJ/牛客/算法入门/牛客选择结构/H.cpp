#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,n;
	cin>>a>>b>>n;
	int num=abs(a)+abs(b);
	if(num<=n&&(n-num)%2==0) cout<<"YES";
	else cout<<"NO";
	return 0;
}
/*#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,n;
    scanf("%d %d %d",&a,&b,&n);
    int sum=abs(a)+abs(b);
    if(n<sum)printf("NO");
    else if((n-sum)%2!=0)printf("NO");
    else printf("YES");
    return 0;
}*/
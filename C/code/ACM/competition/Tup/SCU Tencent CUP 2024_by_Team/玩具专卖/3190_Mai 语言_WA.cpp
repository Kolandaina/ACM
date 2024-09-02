#include<bits/stdc++.h>
using namespace std;
long long n, m, k;
int s[40];
void out(){
//	for(int i=0;i<n;i++){
//		cout<<i<<' '<<s[i]<<endl;
//	}
	for(int i=0;i<=30;i++){
		if(s[i]!=0){
			printf("{%d}",(int)pow(2,i));
			for(int j=1;j<=s[i];j++) printf(",");
			printf("\n");
		}
	}
}
int ws(int x){
	int cnt=0;
	while(x){
		x/=10;
		cnt++;
	}
	return cnt;
}
int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if(m<4){
		puts("-1");
	}
	if(m==4){
		if(k==1){
			puts("{1},");
		}
		else puts("-1");
	}
	int last=0;
	for(int i = 0;i <= n-1;i++,k*=2)
	{
		int m1=m-ws(pow(2,i))-2;
		if(m1<=0) break;
		if(k>m1){
			s[i]+=m1;
			k-=m1;
		}
		else{
			s[i]+=k;
			k=0;
			last=i;
			break;
		}
	}
	if(k>0){
		puts("-1");
		return 0;
	}
	if(last<n-1){
		if(s[last]>1){
			s[last]-=1;
			for(int i=last+1;i<=n-1;i++){
				if(i!=n-1) s[i]+=1;
				else s[i]+=2;
			}
		}
		else{
			s[last-1]-=1;
			for(int i=last;i<=n-1;i++){
				if(i!=n-1) s[i]+=1;
				else s[i]+=2;
			}
		}
	}
	for(int i=0;i<=n-1;i++){
		int num=ws(pow(2,i))+2+s[i];
		if(num>m){
			puts("-1");
			return 0;
		}
	}
	out();
	return 0;
}
/*
3 3
10.000
15.000
16.000
00.000
15.000
15.999
*/

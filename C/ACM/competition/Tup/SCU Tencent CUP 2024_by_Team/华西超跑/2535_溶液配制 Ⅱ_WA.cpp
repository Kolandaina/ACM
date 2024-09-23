#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
#define P 1000000007
#define D double
const D PIE=acos(-1);
int pw[2001];
D a[2000],b[2000];
struct Vector{
	D X,Y;
	int Type(){
		return Y>0||Y==0&&X<0;
	}
	friend D operator*(Vector A,Vector B){
		return A.X*B.Y-A.Y*B.X;
	}
	friend bool operator<(Vector A,Vector B){
		int a=A.Type();
		int b=B.Type();
		if(a!=b){
			return a<b;
		}
		return A*B>0;
	}
	friend bool operator==(Vector A,Vector B){
		return A.X==B.X&&A.Y==B.Y;
	}
};
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		pw[i]=(pw[i-1]*2+1)%P;
	}
	for(int i=0;i<n;i++){
		scanf("%lf%lf",a+i,b+i);
	}
	for(int i=0;i<q;i++){
		D x,y;
		scanf("%lf%lf",&x,&y);
		vector<Vector>A;
		for(int j=0;j<n;j++){
			if(a[j]!=x||b[j]!=y){
				Vector V;
				V.X=a[j]-x;
				V.Y=b[j]-y;
				A.push_back(V);
			}
		}
		sort(A.begin(),A.end());
		int s=A.size();
		/*for(int j=0;j<s;j++){
			cout<<"S "<<A[j].X<<' '<<A[j].Y<<endl;
		}*/
		for(int j=0;j<s;j++){
			A.push_back(A[j]);
		}
		int ans=pw[n],r=0;
		for(int j=0;j<s;j++){
			while(r<j+s&&(A[j]*A[r]>0||A[j]==A[r])){
				r++;
			}
			ans-=pw[r-j-1]+1;
			ans%=P;
		}
		ans=(ans+P)%P;
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 4
0 0
20 0
0 20
20 20
10 10
0 0
30 20.5
0.001 0

5 5
0 0
0 0
20 0
0 20
20 20
10 10
0 0
30 20.5
0.001 0
0 0
*/

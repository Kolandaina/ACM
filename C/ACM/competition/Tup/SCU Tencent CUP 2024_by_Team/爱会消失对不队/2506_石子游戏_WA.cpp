#include<iostream>
const int N=1000010;
int a[N];
using namespace std;
int main(){
	int t;
	cin>>t;
	a[1]=1;
	a[2]=-1;
	for(int i=3;i<N;i++){
		if(i%2==1){
			a[i]=-a[i-1];
		}
		if(i%2==0){
			if(a[i-1]==-1&&a[i/2]==-1){
				a[i]=1;
			}else{
			    a[i]=-1;
			}
		}
	}
	while(t--){
		int n;
		cin>>n;
		if(a[n]==-1){
			cout<<"Bob"<<endl;
		}else{
			cout<<"Alice"<<endl;
		}
	}
	return 0;
}

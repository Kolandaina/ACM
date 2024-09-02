#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4000006;
int phi[MAXN];
bool check[MAXN];
int prime[283150];
int tot;
const int N=4000000;
void phii(){
	phi[1]=1;
	tot=0;
	for(int i=2;i<=N;i++){
		if(!check[i]){
			prime[tot++]=i;
			phi[i]=i-1;
		}
		for(int j=0;j<tot;j++){
			if(i*prime[j]>N)break;
			check[i*prime[j]]=true;
			if(i%prime[j]==0){
				phi[i*prime[j]]=phi[i]*prime[j];
				break;
			}
			else{
				phi[i*prime[j]]=phi[i]*(prime[j]-1);
			}
		}
	}
}

void save_the_people(){
	int n,n2;
	cin>>n;
	n2=2*n;
	auto pos=upper_bound(prime,prime+283146,n2)-prime;
	int now=n2;
	//cout<<prime[pos]<<"\n";
	int al=0;
	bool ok=false;
	while(al<50){
		al++;
		if(now==0){
			//cout<<"n2= "<<n2<<"Yes\n";
			ok=true;
			break;
		}
		auto pp=upper_bound(prime,prime+283146,now)-prime;
		now=prime[pp]-now-1;
	}
	now=n2;
	if(true){
		while(now){
			auto pp=upper_bound(prime,prime+283146,now)-prime;
			int p1=prime[pp]/2;
			now=prime[pp]-now-1;
			for(int i=1;i<=p1-now;i++){
				cout<<p1+1-i<<" "<<p1+i<<"\n";
			}
			
		}
	}
	else cout<<"-1\n";
}

int main(){
	phii();
	//cout<<tot;
	int ttt=1;
	cin>>ttt;
	while(ttt--){
		save_the_people();
	}
	return 0;
}

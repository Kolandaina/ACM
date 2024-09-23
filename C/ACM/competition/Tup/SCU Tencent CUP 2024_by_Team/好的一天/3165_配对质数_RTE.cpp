#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=4e6;
std::vector<bool>is_prime(N+1,true);
std::vector<int>prime;
void sieve(){
	
	is_prime[0]=is_prime[1]=false;
	for(int p=2;p<=N;p++){
		if(!is_prime[p])continue;
		prime.push_back(p);
		for(int q=p+p;q<=N;q+=p){
			if(!is_prime[q])break;
			is_prime[q]=false;
		}
	}
}
vector<pair<int,int> > da;

int hs(int l,int r){
	for(int i=l;i<r;i+=2){
		if(is_prime[i+r]){
			if(i>l){
				hs(l,i-1);
			}
			while(i<r){
				da.push_back({i,r});
				i++;
				r--;
			}
			break;
		}
	}
}

void solve() {
	da.clear();
	int n;
	cin>>n;
	hs(1,2*n);
	for(auto i:da){
		cout<<i.first<<" "<<i.second<<"\n";
	}
}

signed main () {
//	std::ios::sync_with_stdio(false);
//	std::cin.tie(0);

	sieve();
	
//	int sum=0;
//	for(auto i:prime)
//	{
//		sum++;
//		if(sum==100)
//		break;
//		cout<<i<<" ";	
//	}
	
//	std::cout<<[17]<<'\n';
	int t = 1;
	cin >> t;
	for(int i = 0; i < t; ++i) solve ();

	return 0;
}

//3 3
//10.000
//15.000
//16.000
//00.000
//15.000
//15.999

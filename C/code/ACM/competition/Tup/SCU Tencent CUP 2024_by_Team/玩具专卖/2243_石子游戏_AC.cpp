#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n;
inline void work()
{
	cin >> n;
	if(n % 2 == 0)
	{
		if(n > 2)
		{
			puts("Alice");
			return ;
		}
		puts("Bob");
		return ;
	}
	if(n > 3) 
	{
		puts("Bob");
		return ;
	}
	if(n == 3 || n == 1) puts("Alice");
}
int main()
{
	cin >> T;
	while(T --) work();
	return 0;
}

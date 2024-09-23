#include <bits/stdc++.h>
using namespace std;

int main()
{
	int r, x;
	cin>>r>>x;
	printf("%.10f\n",x*(1.0/cos(double(x)/r)-1));
}

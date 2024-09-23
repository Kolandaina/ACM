#include <iostream>
using namespace std;

int T,n;

int main(){
	scanf("%d",&T);
	while(T --){
		scanf("%d",&n);
		if (n == 1 || n == 3 || (n % 2 == 0 && n != 2))
		  printf("Alice\n");
		else
		  printf("Bob\n");
	}
	return 0;
}


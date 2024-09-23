#include<stdio.h>
int Ack(int a, int b) {
	if (a == 0) {
		return b+1;
	}
	else if (a > 0 && b == 0) {
		return Ack(a-1, 1);
	}
	else if(a > 0 && b > 0){
		return Ack(a-1, Ack(a, b-1));
	}
}
int main() {
	int m, n,ret;
	scanf("%d%d", &m, &n);
	ret = Ack(m, n);
	printf("%d",ret);
	return 0;
}

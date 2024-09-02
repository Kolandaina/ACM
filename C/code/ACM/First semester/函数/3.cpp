#include <stdio.h>
#include <string.h>

int main()
{
	char a[200], b[200], c[201];
	int i, j, k, max, lena, lenb;
	
	gets(a);
	gets(b);
	
	lena = strlen(a);
	lenb = strlen(b);
	
	if(lena > lenb) max = lena;
	else max = lenb;
	

	for(i=lena-1, j=lenb-1, k=max; i>=0 && j>=0; i--, j--, k--)	
		c[k] = a[i]+b[j]-'0';
	for( ; i>=0; i--, k--) c[k] = a[i];
	for( ; j>=0; j--, k--) c[k] = b[j];
	
	for(k=max; k>=2; k--)
		if(c[k]-'0'>9)
		{
			c[k] -= 10;
			c[k-1] += 1;
		}
	if(c[1]-'0'>9)
	{
		c[1] -= 10;
		c[0] = 1+'0';
		i=0;
	}
	else i=1;
	
	for(j=i; j<=max; j++)
		printf("%c", c[j]);
	
	return 0;
}

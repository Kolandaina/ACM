#include<bits/stdc++.h>
#include <string.h>
using namespace std;
int main()
{
	char a[10086];
	scanf("%s",&a);
	int shu = strlen(a);
	//if (a[0] == '-')
	//printf ("-");
	int pan = 0;
	int i;
	for (i = shu; i >= 0; i--)
	{
		if (pan == 0 && a[i] == '0')
		    continue;
		if (a[i] == '-')
		    continue;
	    if (a[i] >= '0' && a[i] <= '9')
		{
			printf ("%c",a[i]);
			pan = 1;
		}
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int t1 = n / 2 + 1;
        int t2 = n / 2;
        for (int i = 1; i <= t1; ++i)
		{
            for (int j = 1; j <= t1 - i; ++j)
			{
                printf(" ");
            }
            for (int j = 0; j < i * 2 - 1; ++j)
			{
                printf("*");
            }
            printf("\n");
        }
        for (int i = t2; i > 0; --i)
		{
            for (int j = 1; j <= t1 - i; ++j)
			{
                printf(" ");
            }
            for (int j = 0; j < i * 2 - 1; ++j)
			{
                printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
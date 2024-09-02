#include <bits/stdc++.h>
using namespace std;
int main()
{
    int y, mm, dd, h, m, s, run = 0;
    int a, b, c, d, e, f;
    int sum[3] = {0};
    while (~scanf("%d-%d-%d %d:%d:%d", &y, &mm, &dd, &h, &m, &s))
    {
        run = 0;
        scanf("%d:%d:%d", &a, &b, &c);
        scanf("%d:%d:%d", &d, &e, &f);
        sum[0] = 3600 * h + 60 * m + s;
        sum[1] = 3600 * a + 60 * b + c;
        sum[2] = 3600 * d + 60 * e + f;
        if (sum[1] < sum[2])
        {
            if (sum[0] <= sum[1])
                printf("%d-%02d-%02d %02d:%02d:%02d", y, mm, dd, a, b, c);
            else if (sum[0] < sum[2])
                printf("%d-%02d-%02d %02d:%02d:%02d", y, mm, dd, h, m, s);
            else
            {
                if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                    run = 1;
                if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
                {
                    if (mm == 12 && dd == 31)
                    {
                        y++;
                        mm = 1;
                        dd = 1;
                    }
                    else if (dd == 31)
                    {
                        dd = 1;
                        mm = mm + 1;
                    }
                    else
                        dd++;
                }
                else
                {
                    if (run == 1 && mm == 2 && dd == 29)
                    {
                        mm++;
                        dd = 1;
                    }
                    else if (run == 0 && mm == 2 && dd == 28)
                    {
                        dd = 1;
                        mm = mm + 1;
                    }
                    else if (dd == 30)
                    {
                        dd = 1;
                        mm++;
                    }
                    else
                        dd++;
                }
                printf("%d-%02d-%02d %02d:%02d:%02d", y, mm, dd, a, b, c);
            }
        }
        else if (sum[1] == sum[2])
            printf("%d-%02d-%02d %02d:%02d:%02d", y, mm, dd, h, m, s);
        else
        {
            if (sum[0] <= sum[1] && sum[0] >= sum[2])
                printf("%d-%02d-%02d %02d:%02d:%02d", y, mm, dd, a, b, c);
            else
                printf("%d-%02d-%02d %02d:%02d:%02d", y, mm, dd, h, m, s);
        }
        printf("\n");
    }
    return 0;
}
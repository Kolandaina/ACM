#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double min(double a, double b, double c)
{
    double min;
    if (a > b)
        min = b;
    if (c < min)
        min = c;
    return min;
}
int main()
{
    double n, k, m;
    int t = 0;
    scanf("%lf  %lf", &n, &k);
    if (n == k)
        t = 0;
    else if (n > k)
        t = n - k;
    else
    {
        for (int i = 0;; i++)
        {
            if (k > n * pow(2, 1.0 * i) && k < n * pow(2, 1.0 * i + 1))
            {
                n = n * pow(2, 1.0 * i);
                t = i;
                break;
            }
        }
        if (k == n)
            printf("%lf", t);
        else
        {
            m = min(fabs(n * 2 - k), fabs((n - 1) * 2 - k), fabs((n + 1) * 2 - k));
            if (fabs(n - k) < m)
            {
                t = t + fabs(n - k);
            }
            else if (m == fabs(n * 2 - k))
                t = t + m + 1;
            else
                t = t + m + 2;
        }
    }
    printf("%d", t);

    return 0;
}

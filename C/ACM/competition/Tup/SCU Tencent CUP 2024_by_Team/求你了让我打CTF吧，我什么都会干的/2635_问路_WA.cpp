#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;
const double pi = acos(-1.0);

int main()
{
    double x, r;
    scanf("%lf %lf", &r, &x);
    if(r == 0) { printf("0\n"); return 0;}
    double x1 = x / r, x2 = x / (r * cos(x / r));
    double ans1 = x1 - x2;
    ans1 = sin(ans1);
    ans1 = asin(ans1);
    ans1 = fabs(ans1);
    double ans2 = min(ans1, 2 * pi - ans1);
    printf("%.10f\n", ans2 * r);
    return 0;
}

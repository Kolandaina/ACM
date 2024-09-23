#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<double> a;
        vector<double> b;
        for (int i = 0; i < 2 * n; i++)
        {
            double x, y;
            cin >> x >> y;
            if (x == 0)
            {
                a.push_back(y);
            }
            else
            {
                b.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += sqrt(a[i] * a[i] + b[i] * b[i]);
        }
        printf("%.23lf", sum);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b;
    cin >> a >> b;
    int d = ((sqrt(5.0) + 1) / 2) * abs(a - b);
    if (d == min(a, b))
        cout << "0";
    else
        cout << "1";
    return 0;
}
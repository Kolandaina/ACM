#include <bits/stdc++.h>
using namespace std;
int node(int x)
{
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0 && node(i))
        {
            cout << n / i << endl;
            break;
        }
    }
    return 0;
}
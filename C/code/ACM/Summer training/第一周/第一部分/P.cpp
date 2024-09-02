#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int a, b, c;
    while (cin >> a >> b >> c && (a && b && c))
    {
        a /= gcd(a, b);
        if (a & 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << a - 1 << endl;
        }
    }
    return 0;
}
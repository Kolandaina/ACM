#include <iostream>
using namespace std;
int main()
{
    int k;
    int ans = 0;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int res = k / i;
        for (int j = 1; j <= res; j++)
        {
            ans += res / j;
        }
    }
    cout << ans << endl;
    return 0;
}
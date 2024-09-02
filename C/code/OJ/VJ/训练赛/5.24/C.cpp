#include <iostream>
using namespace std;
int main()
{
    int k;
    cin >> k;
    if (k % 2 == 0 || k % 10 == 5)
    {
        cout << -1 << endl;
        return 0;
    }
    int a = 7, cnt = 1;
    while (1)
    {
        if (a % k == 0)
        {
            break;
        }
        a %= k;
        a = a * 10 + 7;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
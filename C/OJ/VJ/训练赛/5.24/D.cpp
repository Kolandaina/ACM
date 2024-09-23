#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int num = 0, cnt = 0;
        for (int i = 0; i < a; i++)
        {
            int x;
            cin >> x;
            num += x;
            if (x == b)
                cnt++;
        }
        if (cnt == a)
            cout << 0 << endl;
        else if (a * b == num)
            cout << 1 << endl;
        else if (cnt)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
    return 0;
}
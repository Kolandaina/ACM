#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    char s[510][10];
    int a[510];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> s[i][j];
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (s[i][j] == '#')
            {
                cout << j << ' ';
            }
        }
    }
    cout << '\n';
}



int main()
{
    int count = 0;
    cin >> count;
    while (count--)
    {
        solve();
    }
    system("pause");
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
char ans[] = "ok, i agree with you";
int main()
{
    int n;
    cin >> n;
    int y = 0;
    getchar();
    int x = strlen(ans);
    for (int i = 0; i < x; i++)
    {
        cout << ans[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        char a[30];
        cin.getline(a, 30);
        for (int j = 0; j < strlen(a); j++)
        {
            if (a[i] == ans[y])
            {
                y++;
            }
        }
    }
    if (y == 21)
        cout << "Octopus, I love you!";
    else
        cout << "Thank you for your company and wish you happiness.";
    cout << y << endl;
    return 0;
}
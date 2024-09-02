#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    int len = str.size();
    while (n--)
    {
        for (int i = 0; i < len; i++)
        {
            if (str[i] > str[i + 1])
            {
                for (int j = i; j < len; j++)
                {
                    str[j] = str[j + 1];
                }
                break;
            }
        }
        len--;
    }
    int sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '0')
        {
            sum++;
        }
        else
            break;
    }
    int flag = 1;
    for (int i = sum; i < len; i++)
    {
        cout << str[i];
        flag = 0;
    }
    if (flag == 1)
        cout << flag - 1;
    return 0;
}
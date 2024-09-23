/***
 * @Author: your name
 * @Date: 2023-07-07 14:07:49
 * @LastEditTime: 2023-07-07 14:10:12
 * @LastEditors: 羽羽
 * @Description:
 * @FilePath: \pythonProjectd:\C\ATcoder\常规赛\163\A.cpp
 */
#include <bits/stdc++.h>
using namespace std;
void slove()
{

    int n;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        if (s.substr(0, i) < s.substr(i, n - i))
        {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        slove();
    }
    return 0;
}

/***
 * @Author: 羽羽
 * @Date: 2023-07-07 15:37:22
 * @LastEditTime: 2023-07-07 15:37:25
 * @LastEditors: 羽羽
 * @Description:
 * @FilePath: \pythonProjectd:\C\ATcoder\初学者竞赛\301\A.cpp
 */
#include <bits/stdc++.h>

using i64 = long long;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;
    std::string S;
    std::cin >> S;
    int T = std::count(S.begin(), S.end(), 'T');
    int A = std::count(S.begin(), S.end(), 'A');

    if (T > A)
        std::cout << "T\n";
    else if (T <= A)
    {
        std::cout << "A\n";
    }
    else
    {
        std::cout << char('A' ^ 'T' ^ S.back()) << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    unordered_map<char, int> lst;
    lst.insert({str[0], 0});
    int check = 1;
    for (int i = 1; i < str.size(); i++)
    {
        if (lst.find(str[i]) == lst.end())
        {
            lst.insert({str[i], 1 - lst[str[i - 1]]});
        }
        else if (lst[str[i]] == lst[str[i - 1]])
        {
            check = 0;
        }
    }
    if (check)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
        slove();
    return 0;
}

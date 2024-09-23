#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
using namespace std;
typedef long long LL;

const int N = 1e5 + 10;
const int MOD = 1e9 + 7;

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    int c1 = 0, c2 = 0;
    for (char i : s)
    {
        if (i == '(')
            c1++;
        else
            c2++;
    }
    if (c1 != c2)
    {
        cout << -1 << endl;
        return;
    }
    stack<int> stk1, stk2;
    vector<int> v;
    bool flag1 = false, flag2 = false;
    for (char i : s)
    {
        if (i == '(')
        {
            if (!stk2.empty())
            {
                v.push_back(2);
                stk2.pop();
            }
            else
            {
                stk1.push(0);
                flag2 = true;
                v.push_back(1);
            }
        }
        else if (i == ')' && !stk1.empty())
        {
            stk1.pop();
            v.push_back(1);
        }
        else if (i == ')')
        {
            stk2.push(0);
            flag1 = true;
            v.push_back(2);
        }
    }
    if (!flag1 || !flag2)
    {
        cout << 1 << endl;
        for (int i = 1; i <= n; ++i)
        {
            cout << 1 << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << 2 << endl;
        for (auto i : v)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}

signed main()
{
    ios;
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
}
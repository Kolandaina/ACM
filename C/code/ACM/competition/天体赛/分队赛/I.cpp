#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
template <class T1>
std::istream &operator>>(std::istream &cin, std::vector<T1> &a)
{
    for (auto &x : a) cin >> x;
    return cin;
}
template <class T1>
std::ostream &operator<<(std::ostream &cout, const std::vector<T1> &a)
{
    int n = a.size();
    if (!n) return cout;
    cout << a[0];
    for (int i = 1; i < n; i++) cout << ' ' << a[i];
    return cout;
}
inline void slove()
{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    std::cin >> a;
    std::vector<char> b(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        std::cin >> b[i];
    }
    std::stack<int> sum;
    std::stack<char> fuhao;
    for (int i = 0; i < n; i++)
    {
        sum.push(a[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        fuhao.push(b[i]);
    }
    while (!fuhao.empty())
    {
        int temp = sum.top();
        sum.pop();
        int temp1 = sum.top();
        sum.pop();
        if (fuhao.top() == '+')
        {
            sum.push(temp + temp1);
        }
        else if (fuhao.top() == '-')
        {
            sum.push(temp1 - temp);
        }
        else if (fuhao.top() == '*')
        {
            sum.push(temp * temp1);
        }
        else if (fuhao.top() == '/')
        {
            if (temp == 0)
            {
                std::cout << "ERROR: " << temp1 << "/" << temp << endl;
                return;
            }
            else
            {
                sum.push(temp1 / temp);
            }
        }
        fuhao.pop();
    }
    std::cout << sum.top() << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--) slove();
    return 0;
}
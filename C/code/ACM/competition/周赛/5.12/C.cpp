#include <bits/stdc++.h>
#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;
std::stack<int> st;
std::priority_queue<int> pq;
std::map<int, int> mp;
inline void slove()
{
    int op;
    std::cin >> op;
    if (op == 0)
    {
        int x;
        std::cin >> x;
        st.push(x);
        pq.push(x);
        mp[x]++;
    }
    else if (op == 1)
    {
        if (!st.empty())
        {
            int x = st.top();
            st.pop();
            mp[x]--;
        }
    }
    else if (op == 2)
    {
        while (!st.empty() && mp[pq.top()] == 0)
        {
            pq.pop();
        }
    }
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
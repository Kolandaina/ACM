#include <bits/stdc++.h>

#define int long long
#define endl "\n"
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int INF = 0x3f3f3f3f3f3f3f3f;

inline void slove() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::set<char> st;
    for (auto c: s) st.insert(c);
    std::string res;
    for (auto c: st) res.push_back(c);
    std::map<char, int> mp1;
    std::map<int, char> mp2;
    for (int i = 0; i < res.length(); i++) {
        mp1[res[i]] = i;
        mp2[i] = res[i];
    }
    for (auto c: s)std::cout << mp2[res.length() - mp1[c] - 1];
    std::cout << endl;
}

signed main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    std::cin >> t;
    while (t--) slove();
    return 0;
}
#define  _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p = 2e5 + 10, mod = 1e9 + 7;

int a[110][p], n, dp[p], pre[p];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    getline(cin, s);
    vector<string>vc;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ')continue;
        string tmp = "";
        for (; i < s.length() && s[i] != ' '; i++) {
            tmp += s[i];
        }
        vc.push_back(tmp);
    }
    vector<int>st;
    st.push_back(0);
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i] == "library")st.back() = (st.back() + 1) % mod;
        if (vc[i] == "repeat")st.push_back(0);
        if (vc[i][0] >= '0' && vc[i][0] <= '9')st.back() = st.back() * stoi(vc[i]) % mod;
        if (vc[i] == "times") {
            int x = st.back();
            st.pop_back();
            st.back() = (st.back() + x) % mod;
        }
    }
    cout << st.back() << endl;
}
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int mod = 20220911;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    getline(cin, s);
    int n = s.size();
    vector <string> a;
    for (int i = 0; i < n; i ++) {
        if (s[i] == ' ') continue;
        string t = "";
        for (; i < n && s[i] != ' '; i ++)
            t = t + s[i];
        a.push_back(t);
    }
    int m = a.size();
    vector <LL> b;
    b.push_back(0);
    for (int i = 0; i < m; i ++) {
        if (a[i] == "library") {
            b.back() = (b.back() + 1) % mod;
        } else if (a[i] == "repeat") {
            b.push_back(0);
        } else if ('0' <= a[i][0] && a[i][0] <= '9') {
            b.back() = b.back() * stoi(a[i]) % mod;
        } else if (a[i] == "times") {
            LL t = b.back();
            b.pop_back();
            b.back() = (b.back() + t) % mod;
        }
    }
    cout << b.back() << "\n";
    return 0;
}
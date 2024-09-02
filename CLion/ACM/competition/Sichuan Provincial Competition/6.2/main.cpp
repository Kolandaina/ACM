#include<bits/stdc++.h>
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
const int N = 3e5 + 10, mod = 998244353;
typedef pair<int, int> PII;
int n, m, res;
int X[210], L[210], D[210];
vector<int> v;
bool check(int k) {
    for (int i = 1; i <= n; i++) {
        D[i] = abs(X[i] - k);
    }
    sort(D + 1, D + n + 1);
    bool f = true;
    for (int i = 1; i <= n; i++) {
        if (L[i] < D[i]) {
            return false;
        }
    }
    return true;
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> X[i];
    for (int i = 1; i <= n; i++) cin >> L[i];
    sort(L + 1, L + n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v.push_back(X[i] + L[j]);
            v.push_back(X[i] - L[j]);
        }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 0; i < v.size() - 1; i++) {
        if (check(v[i] + 1)) res += v[i + 1] - v[i] - 1;
    }
    for (int i = 0; i < v.size(); i++) {
        if (check(v[i])) res++;
    }
    cout << res;
    return 0;
}

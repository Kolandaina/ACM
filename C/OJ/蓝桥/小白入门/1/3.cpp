#include <bits/stdc++.h>
#define int long long
#define endl "\n"
inline void slove()
{
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // std:: cin >> t;
    while (t--)
        slove();
    return 0;
}
/*
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉
auto init =  []{
    for (int i = 2; i < N; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            //mp[i] = 1;
        }
        for (int j = 0; primes[j] <= N / i; j++) {
            st[primes[j] * i] = true; // 以primes[j]为最小质因子筛
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
    return 0;
}();
void solve() {
    int n, m;
    ll ans = LLONG_MIN;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < cnt; i++) {
        if (primes[i] > n) break;
        int k = primes[i];
        ll sum = accumulate(a.begin(), a.begin() + k , 0LL);
        ans = max(ans, sum);
        for (int i = k; i < n; i++) {
            sum += a[i] - a[i - k];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}
*/
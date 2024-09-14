#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
signed main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    if ((sum - a[n]) < a[n]) {
        sum += (a[n] - (sum - a[n]));
    }
    cout << sum << endl;
    return 0;
}
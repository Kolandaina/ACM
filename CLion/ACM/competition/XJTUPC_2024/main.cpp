#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
std::vector<int> a(N + 1);
std::vector<int> b(N + 1);
int n, m;

bool check(int x) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < x) {
            int res = x - a[i];
            if (res > b[i]) return false;
            sum += res;
        }
    }
    if (sum > m) return false;
    return true;
}

signed main() {

    std::cin >> n >> m;
    for (int i = 0; i < n; i++)std::cin >> a[i];
    for (int i = 0; i < n; i++)std::cin >> b[i];
    int l = 0, r = 1e12;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid))l = mid;
        else r = mid - 1;
    }

    std::cout << l << endl;
    return 0;
}
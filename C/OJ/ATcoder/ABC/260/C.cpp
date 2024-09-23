#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
inline void slove()
{
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<long long> R(N), B(N);
    B[0] = 1;
    R[0] = 0;
    for (int i = 1; i < N; i++)
    {
        B[i] = R[i - 1] + B[i - 1] * Y;
        R[i] = R[i - 1] + B[i] * X;
    }
    cout << R[N - 1] << endl;
}
signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        slove();
    return 0;
}
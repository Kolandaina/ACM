#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int N = 400025;

vector<int> vt[N], vtNot;
int st[N];
int arr[N], sum[N];
void init()
{
    for (int i = 1; i < N; ++i)
    {
        for (int j = 1; j * i < N; ++j)
        {
            vt[j * i].push_back(i);
        }
    }
}

int main()
{
    init();

    int t;
    scanf("%d", &t);
    int num = 0;
    vtNot.push_back(0);
    for (int i = 1; i < N; ++i)
    {
        if (vt[i].size() % 2 == 1)
            vtNot.push_back(i);
    }
    while (t--)
    {
        long long ans = 0;
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            ans += (n - i + 1);
            scanf("%d", &arr[i]);
            sum[i] = sum[i - 1] ^ arr[i];
        }
        for (int i = 0; i <= 2 * n; ++i)
            st[i] = 0;
        st[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (auto v : vtNot)
            {
                if (st[sum[i] ^ v] && (sum[i] ^ v) <= 2 * n)
                    ans -= st[sum[i] ^ v];
            }
            st[sum[i]]++;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
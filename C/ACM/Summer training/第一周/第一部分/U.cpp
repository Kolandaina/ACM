#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N], b[N];
long long ans;
void mergeSort(int l, int r)
{
    int mid = (l + r) / 2;
    if (l == r)
        return;
    else
    {
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
    }
    int i = l;
    int j = mid + 1, t = l;
    while (i <= mid && j <= r)
    {
        if (a[i] > a[j])
        {
            ans += mid - i + 1;
            b[t++] = a[j];
            ++j;
        }
        else
        {
            b[t++] = a[i];
            ++i;
        }
    }
    while (i <= mid)
    {
        b[t++] = a[i];
        ++i;
    }
    while (j <= r)
    {
        b[t++] = a[j];
        ++j;
    }
    for (int i = l; i <= r; ++i)
    {
        a[i] = b[i];
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    mergeSort(1, n);
    cout << ans << endl;
    return 0;
}
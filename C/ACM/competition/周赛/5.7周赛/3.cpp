#include <bits/stdc++.h>
using namespace std;
int count_bits(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x & 1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](int x, int y)
         { 
        if(count_bits(x) == count_bits(y))
        {
            return x<y;
        }
        return count_bits(x) < count_bits(y); });
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

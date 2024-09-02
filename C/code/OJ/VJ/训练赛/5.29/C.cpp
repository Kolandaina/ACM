#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int a[100];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n);
        cout << abs(a[0] - a[n - 1]) << endl;
        // cout<<*max_element(a,a+n)-*min_element(a,a+n)<<endl;
    }
    return 0;
}
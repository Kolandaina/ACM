#include "bits/stdc++.h"

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int n;
int a[N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int ans = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if ((a[i] & a[j]) == 0)
                {
                    bool flag = true;
                    for (int k = i + 1; k < j; ++k)
                    {
                        if ((a[k] & a[j]) != 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if (flag)
                    {
                        ans = max(ans, j - i + 1);
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
        cout << ans << endl;
    }
}
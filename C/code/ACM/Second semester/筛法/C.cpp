#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
void div(map<int, int> &mp, int n)
{
    int ans = 1;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                mp[i]++;
                n /= i;
            }
            ans *= (mp[i] + 1);
        }
    }
    if (n > 1)
    {
        mp[n]++;
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        div(mp, i);
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
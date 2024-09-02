#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
map<int, int> mp;
int main()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        int sum = 1;
        while (true)
        {
            if (x & 1 == 1)
                break;
            x >>= 1;
            sum++;
        }
        mp[sum]++;
    }
    for (auto iter = mp.begin(); iter != mp.end(); iter++)
    {
        cout << iter->first << " " << iter->second << endl;
    }
    return 0;
}
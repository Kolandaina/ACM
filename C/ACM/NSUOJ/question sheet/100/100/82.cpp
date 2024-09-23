#include <iostream>
#include <map>
using namespace std;
map<int, int> mp;
int main()
{
    int n, m;
    int b[1010];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int flag = 0;
    for (int i = 0; i < m; i++)
    {
        mp[b[i]]--;
        if (mp[b[i]] < 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
string dx[30] = {"1000", "0100", "0010", "0001", "1100", "0110", "0011", "1110", "0111", "1111",
                 "2000", "0200", "0020", "0002", "2200", "0220", "0022", "2220", "0222", "2222"};
void bfs()
{
    mp["0000"] = 0;
    queue<string> q;
    q.push("0000");
    while (!q.empty())
    {
        string top = q.front();
        q.pop();
        for (int i = 0; i < 20; i++)
        {
            string node = top;
            string d = dx[i];
            for (int j = 0; j < 4; j++)
            {
                if (d[j] == '1')
                {
                    node[j] = (node[j] - '0' + 1 + 10) % 10 + '0';
                }
                else if (d[j] == '2')
                {
                    node[j] = (node[j] - '0' - 1 + 10) % 10 + '0';
                }
            }
            if (!mp.count(node))
            {
                mp[node] = mp[top] + 1;
                q.push(node);
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    bfs();
    while (t--)
    {
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < 4; i++)
        {
            a[i] = (b[i] - a[i] + 10) % 10 + '0';
        }
        cout << mp[a] << endl;
    }
    return 0;
}
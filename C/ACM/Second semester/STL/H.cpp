#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> q;
    int n, a;
    int num = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        q.push(a);
    }
    while (q.size() >= 2)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        num += x + y;
        q.push(x + y);
    }
    cout << num << endl;
}
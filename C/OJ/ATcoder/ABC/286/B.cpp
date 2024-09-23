#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    string s, t;
    cin >> n >> s;
    for (auto c : s)
    {
        t.push_back(c);
        if (t.size() == 1)
            continue;
        if (t[t.size() - 2] == 'n' && t[t.size() - 1] == 'a')
        {
            t.pop_back();
            t = t + "ya";
        }
    }
    cout << t;
    return 0;
}
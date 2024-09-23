#include <bits/stdc++.h>
using namespace std;
map<string, int> str;
int main()
{
    int n;
    cin >> n;
    string a;
    map<string, int>::iterator ite;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        ite = str.find(a);
        if (ite == str.end())
        {
            str[a] = 0;
            cout << "OK" << endl;
        }
        else
        {
            str[a]++;
            cout << ite->first << ite->second << endl;
        }
    }
    return 0;
}
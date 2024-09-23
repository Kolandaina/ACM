#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        string s;
        set<string> st;
        cin >> m;
        cin >> s;
        for (int i = 0; i < m - 1; i++)
        {
            string s2;
            s2 += s[i];
            s2 += s[i + 1];
            st.insert(s2);
        }
        cout << st.size() << endl;
    }
    return 0;
}
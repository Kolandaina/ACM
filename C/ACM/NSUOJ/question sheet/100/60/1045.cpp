#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int count = 0;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {

        if (isalpha(str[i]))
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}

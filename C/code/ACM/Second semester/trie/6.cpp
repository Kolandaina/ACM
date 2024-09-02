#include <iostream>
#include <vector>
using namespace std;

vector<int> compute_prefix(const string &pattern)
{
    int m = pattern.length();
    vector<int> prefix(m, 0);
    int length = 0;
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            prefix[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = prefix[length - 1];
            }
            else
            {
                prefix[i] = 0;
                i++;
            }
        }
    }

    return prefix;
}

int main()
{
    int L;
    cin >> L;
    string s1;
    cin >> s1;
    int n = s1.length();
    vector<int> prefix = compute_prefix(s1);
    cout << n - prefix[n - 1] << endl;
    return 0;
}
